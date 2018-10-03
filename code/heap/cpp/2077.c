#include "Heap.hpp"

int log(const char *format,...);

map<unsigned int, Heap *>heaps;

HeapChunk *Heap::malloc(unsigned int pid, unsigned int chunk_base, unsigned int size, unsigned int time) {
    HeapChunk *newChunk;

    if (!time) time = gettime();
    newChunk = new HeapChunk(pid, chunk_base, chunk_base+size, time);

    openChunks[chunk_base] = newChunk;
    chunks.push_back(newChunk);

    if (top < newChunk->top)   top  = newChunk->top;
    if (base > newChunk->base) base = newChunk->base;

    return newChunk;
}

HeapChunk *Heap::free(unsigned int pid, unsigned int chunk_base, unsigned int time) {
    HeapChunk *freeChunk;

    if (!time) time = gettime();

    if (openChunks.find(chunk_base) == openChunks.end()) {
        // addEvent("Double free", time);
        return NULL;
    }

    freeChunk = openChunks[chunk_base];

    // if (freeChunk->pid != pid)
    //     addEvent("Chunk freed from different PID.", time);
    openChunks.erase(chunk_base);
    freeChunk->freeTime = time;

    return freeChunk;
}

HeapChunk *Heap::realloc(unsigned int pid, unsigned int old_base, unsigned int new_base, unsigned int new_size, unsigned int time) {
    if (!time) time = gettime();

    free(pid, old_base, time);
    return malloc(pid, new_base, new_size, time);
}

void Heap::addEvent(char *comment, unsigned int time) {
    HeapChunk *newChunk;

    if (!time) time = gettime();
    events.push_back(new HeapEvent(comment, time));
	log("%s\n", comment);
}

Heap *getHeap(unsigned int handle) {
	if (heaps.find(handle) == heaps.end())
        heaps[handle] = new Heap();

    return heaps[handle];
}

void Heap::clear() {
	HeapChunk *c;

	for (ts_vector<HeapChunk *>::iterator chunk = chunks.begin(); chunk != chunks.end(); ++chunk)
		delete  *chunk;
	chunks.clear();

    for (ts_vector<HeapEvent *>::iterator event = events.begin(); event!= events.end(); ++event) 
        delete (*event);
	events.clear();

	openChunks.clear();
	allocTime = gettime();
	base = 0xffffffff;
	top  = 0;
}

void clearHeap(unsigned int handle) {
	if (heaps.find(handle) == heaps.end())
        return;

	heaps[handle]->clear();
}

void clearHeaps() {
    map<unsigned int, Heap *>::iterator heap;

	for (heap = heaps.begin(); heap != heaps.end(); ++heap)
		heap->second->clear();

	heaps.clear();
}