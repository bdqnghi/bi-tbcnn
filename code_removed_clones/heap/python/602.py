#
# Module which supports allocation of memory from an mmap
#
# multiprocessing/heap.py
#
# Copyright (c) 2006-2008, R Oudkerk
# Licensed to PSF under a Contributor Agreement.
#
from __future__ import absolute_import

import bisect
import mmap
import os
import sys
import threading
import itertools

from ._ext import _billiard, win32
from .util import Finalize, info, get_temp_dir
from .forking import assert_spawning, ForkingPickler

__all__ = ['BufferWrapper']

try: INDENT
    maxsize = sys.maxsize
DEDENT except AttributeError: INDENT
    maxsize = sys.maxint

#
# Inheirtable class which wraps an mmap, and from which blocks can be allocated
#

DEDENT if sys.platform == 'win32': INDENT

    class Arena(object): INDENT

        _counter = itertools.count()

        def __init__(self, size): INDENT
            self.size = size
            self.name = 'pym-%d-%d' % (os.getpid(), Arena._counter.next())
            self.buffer = mmap.mmap(-1, self.size, tagname=self.name)
            assert win32.GetLastError() == 0, 'tagname already in use'
            self._state = (self.size, self.name)

DEDENT         def __getstate__(self): INDENT
            assert_spawning(self)
            return self._state

DEDENT         def __setstate__(self, state): INDENT
            self.size, self.name = self._state = state
            self.buffer = mmap.mmap(-1, self.size, tagname=self.name)
            assert win32.GetLastError() == win32.ERROR_ALREADY_EXISTS

DEDENT DEDENT DEDENT else: INDENT

    class Arena(object): INDENT

        _counter = itertools.count()

        def __init__(self, size, fileno=-1): INDENT
            from .forking import _forking_is_enabled
            self.size = size
            self.fileno = fileno
            if fileno == -1 and not _forking_is_enabled: INDENT
                name = os.path.join(
                    get_temp_dir(),
                    'pym-%d-%d' % (os.getpid(), self._counter.next()))
                self.fileno = os.open(
                    name, os.O_RDWR | os.O_CREAT | os.O_EXCL, 0600)
                os.unlink(name)
                os.ftruncate(self.fileno, size)
DEDENT             self.buffer = mmap.mmap(self.fileno, self.size)

DEDENT DEDENT     def reduce_arena(a): INDENT
        if a.fileno == -1: INDENT
            raise ValueError('Arena is unpicklable because'
                             'forking was enabled when it was created')
DEDENT         return Arena, (a.size, a.fileno)

DEDENT     ForkingPickler.register(Arena, reduce_arena)

#
# Class allowing allocation of chunks of memory from arenas
#


DEDENT class Heap(object): INDENT

    _alignment = 8

    def __init__(self, size=mmap.PAGESIZE): INDENT
        self._lastpid = os.getpid()
        self._lock = threading.Lock()
        self._size = size
        self._lengths = []
        self._len_to_seq = {}
        self._start_to_block = {}
        self._stop_to_block = {}
        self._allocated_blocks = set()
        self._arenas = []
        # list of pending blocks to free - see free() comment below
        self._pending_free_blocks = []

DEDENT     @staticmethod
    def _roundup(n, alignment): INDENT
        # alignment must be a power of 2
        mask = alignment - 1
        return (n + mask) & ~mask

DEDENT     def _malloc(self, size): INDENT
        # returns a large enough block -- it might be much larger
        i = bisect.bisect_left(self._lengths, size)
        if i == len(self._lengths): INDENT
            length = self._roundup(max(self._size, size), mmap.PAGESIZE)
            self._size *= 2
            info('allocating a new mmap of length %d', length)
            arena = Arena(length)
            self._arenas.append(arena)
            return (arena, 0, length)
DEDENT         else: INDENT
            length = self._lengths[i]
            seq = self._len_to_seq[length]
            block = seq.pop()
            if not seq: INDENT
                del self._len_to_seq[length], self._lengths[i]

DEDENT DEDENT         (arena, start, stop) = block
        del self._start_to_block[(arena, start)]
        del self._stop_to_block[(arena, stop)]
        return block

DEDENT     def _free(self, block): INDENT
        # free location and try to merge with neighbours
        (arena, start, stop) = block

        try: INDENT
            prev_block = self._stop_to_block[(arena, start)]
DEDENT         except KeyError: INDENT
            pass
DEDENT         else: INDENT
            start, _ = self._absorb(prev_block)

DEDENT         try: INDENT
            next_block = self._start_to_block[(arena, stop)]
DEDENT         except KeyError: INDENT
            pass
DEDENT         else: INDENT
            _, stop = self._absorb(next_block)

DEDENT         block = (arena, start, stop)
        length = stop - start

        try: INDENT
            self._len_to_seq[length].append(block)
DEDENT         except KeyError: INDENT
            self._len_to_seq[length] = [block]
            bisect.insort(self._lengths, length)

DEDENT         self._start_to_block[(arena, start)] = block
        self._stop_to_block[(arena, stop)] = block

DEDENT     def _absorb(self, block): INDENT
        # deregister this block so it can be merged with a neighbour
        (arena, start, stop) = block
        del self._start_to_block[(arena, start)]
        del self._stop_to_block[(arena, stop)]

        length = stop - start
        seq = self._len_to_seq[length]
        seq.remove(block)
        if not seq: INDENT
            del self._len_to_seq[length]
            self._lengths.remove(length)

DEDENT         return start, stop

DEDENT     def _free_pending_blocks(self): INDENT
        # Free all the blocks in the pending list - called with the lock held
        while 1: INDENT
            try: INDENT
                block = self._pending_free_blocks.pop()
DEDENT             except IndexError: INDENT
                break
DEDENT             self._allocated_blocks.remove(block)
            self._free(block)

DEDENT DEDENT     def free(self, block): INDENT
        # free a block returned by malloc()
        # Since free() can be called asynchronously by the GC, it could happen
        # that it's called while self._lock is held: in that case,
        # self._lock.acquire() would deadlock (issue #12352). To avoid that, a
        # trylock is used instead, and if the lock can't be acquired
        # immediately, the block is added to a list of blocks to be freed
        # synchronously sometimes later from malloc() or free(), by calling
        # _free_pending_blocks() (appending and retrieving from a list is not
        # strictly thread-safe but under cPython it's atomic thanks
        # to the GIL).
        assert os.getpid() == self._lastpid
        if not self._lock.acquire(False): INDENT
            # can't aquire the lock right now, add the block to the list of
            # pending blocks to free
            self._pending_free_blocks.append(block)
DEDENT         else: INDENT
            # we hold the lock
            try: INDENT
                self._free_pending_blocks()
                self._allocated_blocks.remove(block)
                self._free(block)
DEDENT             finally: INDENT
                self._lock.release()

DEDENT DEDENT DEDENT     def malloc(self, size): INDENT
        # return a block of right size (possibly rounded up)
        assert 0 <= size < maxsize
        if os.getpid() != self._lastpid: INDENT
            self.__init__()                     # reinitialize after fork
DEDENT         self._lock.acquire()
        self._free_pending_blocks()
        try: INDENT
            size = self._roundup(max(size, 1), self._alignment)
            (arena, start, stop) = self._malloc(size)
            new_stop = start + size
            if new_stop < stop: INDENT
                self._free((arena, new_stop, stop))
DEDENT             block = (arena, start, new_stop)
            self._allocated_blocks.add(block)
            return block
DEDENT         finally: INDENT
            self._lock.release()

#
# Class representing a chunk of an mmap -- can be inherited
#


DEDENT DEDENT DEDENT class BufferWrapper(object): INDENT

    _heap = Heap()

    def __init__(self, size): INDENT
        assert 0 <= size < maxsize
        block = BufferWrapper._heap.malloc(size)
        self._state = (block, size)
        Finalize(self, BufferWrapper._heap.free, args=(block,))

DEDENT     def get_address(self): INDENT
        (arena, start, stop), size = self._state
        address, length = _billiard.address_of_buffer(arena.buffer)
        assert size <= length
        return address + start

DEDENT     def get_size(self): INDENT
        return self._state[1]
DEDENT DEDENT 
