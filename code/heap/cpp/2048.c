#include "Heap.hpp"

#define CHANGUI 0x100

// To do
// [ ] Use an internal variable to mantain time. When time is set to 0, make time == order of call
// [ ] check for overlapping chunks (when alloc() is called)
// [ ] make two different calls per function:
//     [ ] malloc_enter(), malloc_return()
//     [ ] free_enter(), free_return()
//     [ ] realloc_enter(), realloc_return(), 
//     [ ] etc.
//

bool operator<(const HeapChunk &t, const HeapChunk &other) {
	return ((t.base<other.base) || (t.base==other.base && t.allocTime<other.allocTime));
}

bool operator<(const HeapRegion &t, const HeapRegion &other) {
	return ((t.base<other.base) || (t.base==other.base && t.allocTime<other.allocTime));
}

void HeapRegion::alloc(unsigned int base, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapChunk toFind(base, base+size, time, caller, pid);

    if (top < toFind.top) {
        top = toFind.top + CHANGUI;
        verprintf(3,("Readjusting base to 0x%08x\n", top));
    }
	chunks.insert(toFind);
}

void HeapRegion::free(unsigned int base, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapChunk toFind(base, 0, time, caller, pid);

    if (!chunks.size()) return;
	set<HeapChunk>::iterator a=chunks.lower_bound(toFind);
	a--;

	if (a->base == toFind.base) {
		// --a;    verprintf(3,("free found -1: %d 0x%08x %lu %lu\n", a->freeTime == 0.0, a->base, a->allocTime, a->freeTime));    a++;
		        verprintf(2,("free found  0: %d 0x%08x %lu %lu\n", a->freeTime == 0.0, a->base, a->allocTime, a->freeTime));
		// ++a;    verprintf(3,("free found +1: %d 0x%08x %lu %lu\n", a->freeTime == 0.0, a->base, a->allocTime, a->freeTime));    a--;
		if (a->freeTime != 0.0) {
			qprintf(("Freeing a chunk that's already free: 0x%08x\n", toFind.base));
		} else {
			((HeapChunk*)&*a)->setFreeTime(toFind.allocTime);
			((HeapChunk*)&*a)->setFreeCaller(toFind.allocCaller);
		}
	} else {
		verprintf(2,("Found: 0x%08x %lf\n", a->base, a->allocTime));
		qprintf(("Freeing a not allocated chunk: 0x%08x\n", toFind.base));
	}
}

void HeapRegion::realloc(unsigned int base, unsigned int newBase, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller) {
    free(base, time, pid, caller);
    alloc(newBase, size, time, pid, caller);
}

void HeapRegion::setLimits() {

	set<HeapChunk>::iterator i=chunks.begin();

	minAddr = i->base;
	maxAddr = i->top;
	minTime = i->allocTime;
	maxTime = i->freeTime;

    if (i == chunks.end()) return;
	for (i++;i != chunks.end(); i++) {
		if (minAddr > i->base) minAddr = i->base;

		if (maxAddr < i->top) maxAddr = i->top;

		if (minTime > i->allocTime) minTime = i->allocTime;

		if (maxTime < i->allocTime) maxTime = i->allocTime;
		if (maxTime < i->freeTime) maxTime = i->freeTime;
	}

	for (i=chunks.begin();i != chunks.end(); i++)
		if (i->freeTime == 0) 
			((HeapChunk*)&*i)->setFreeTime(maxTime);
}

void Heap::mmap(unsigned int base, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapRegion toFind(base, base+size, time, caller, pid);

    if (autoRegions) return;
    _mmap(base, size, time, pid, caller);
}

void Heap::_mmap(unsigned int base, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapRegion toFind(base, base+size, time, caller, pid);

    verprintf(1,("[%d] mmap(0x%08x, 0x%08x) [%lu]\n", regions.size(), base, size, time));
    if (!size) return;

	set<HeapRegion>::iterator a=regions.lower_bound(toFind);

    if (a != regions.end()) {
        --a;

        // --a; verprintf(3,("mmap found -1: 0x%08x-0x%08x %lu %lu\n", a->base, a->top, a->allocTime, a->freeTime)); a++;
             verprintf(2,("mmap found  0: 0x%08x-0x%08x %lu %lu\n", a->base, a->top, a->allocTime, a->freeTime));
        // ++a; verprintf(3,("mmap found +1: 0x%08x-0x%08x %lu %lu\n", a->base, a->top, a->allocTime, a->freeTime)); a--;

        if (a->contains(base-1)) {
            // new starts inside old
            if (a->contains(base+size-1)) {
                // new contained in old, just return
                verprintf(2,("Old Region included new region: 0x%08x-0x%08x [%lu]\n", a->base, a->top, a->allocTime));
                return;
            }
            if (a->top < base+size) {
                // new extends old
                verprintf(2,("Extending up region at 0x%08x-0x%08x [%lu]\n", a->base, a->top, a->allocTime));
                ((HeapRegion*)&*a)->setTop(base+size);
                return;
            }
        } else if (a->contains(base+size)) {
            if (a->contains(base)) {
                // new contained in old, just return
                verprintf(2,("Old Region included new region: 0x%08x-0x%08x [%lu]\n", a->base, a->top, a->allocTime));
                return;
            }
            if (a->base > base) {
                // new is right before old (new extends old to lower memory)
                verprintf(2,("Extending down region at 0x%08x-0x%08x [%lu]\n", a->base, a->top, a->allocTime));
                ((HeapRegion*)&*a)->setBase(base);
                return;
            }
        }
    }
    regions.insert(toFind);
}

void Heap::munmap(unsigned int base, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapRegion toFind(base, 0, time, caller, pid);

    if (autoRegions) return;
	verprintf(1,("[%d] munmap(0x%08x) [%lu]\n", pid, base, time));

}

void Heap::realloc(unsigned int base, unsigned int newBase, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller) {
	verprintf(1,("[%d] realloc(0x%08x,0x%08x,0x%08x) [%lu]\n", pid, base, newBase, size, time));

    free(base, time, pid, caller);
    alloc(newBase, size, time, pid, caller);
}

void Heap::alloc(unsigned int base, unsigned int size, unsigned int time, unsigned int pid, unsigned int caller, unsigned int dontRecurse) {
    HeapRegion toFind(base, base+size, time, caller, pid);

	verprintf(1,("[%d] alloc(%d) [%lu] = 0x%08x\n", pid, size, time, base));

	set<HeapRegion>::iterator a=regions.lower_bound(toFind);

    if (a != regions.end() && (--a)->contains(base)) {

        // a--; verprintf(3,("region alloc found -1 (%d): 0x%08x-0x%08x %lu %lu\n", a->contains(base), a->base, a->top, a->allocTime, a->freeTime)); a++;
             verprintf(2,("region alloc found  0 (%d): 0x%08x-0x%08x %lu %lu\n", a->contains(base), a->base, a->top, a->allocTime, a->freeTime));
        // a++; verprintf(3,("region alloc found +1 (%d): 0x%08x-0x%08x %lu %lu\n", a->contains(base), a->base, a->top, a->allocTime, a->freeTime)); a--;

        a->alloc(base, size, time, pid, caller);
    } else {
        if (autoRegions && !dontRecurse) {
            _mmap(base-CHANGUI,(size+CHANGUI-1+CHANGUI)&~(CHANGUI-1),time,pid,caller);
            alloc(base, size, time, pid, caller, 1);
        } else {
            verprintf(2,("alloc(0x%08x, 0x%08x) in loose region\n", base, size));
            loose.alloc(base,size,time,pid,caller);
        }
    }
}

void Heap::free(unsigned int base, unsigned int time, unsigned int pid, unsigned int caller) {
    HeapRegion toFind(base, 0, time, caller, pid);

	verprintf(1,("[%d] free(0x%08x) [%lu]\n", toFind.pid, toFind.base,toFind.allocTime));

	set<HeapRegion>::iterator a=regions.lower_bound(toFind);

    if (a != regions.end() && (a--, a->contains(base))) {
        verprintf(3,("region free found (%d): 0x%08x-0x%08x %lu %lu\n", a->contains(base), a->base, a->top, a->allocTime, a->freeTime));
        a->free(base, time, pid, caller);
    } else {
        verprintf(2,("free(0x%08x) in loose region\n", base));
        loose.free(base, time, pid, caller);
    }
}
