# Copyright (c) 2009 Denis Bilenko, denis.bilenko at gmail com
# Copyright (c) 2010 Eventlet Contributors (see AUTHORS)
# and licensed under the MIT license:
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

"""Synchronized queues.

The :mod:`eventlet.queue` module implements multi-producer, multi-consumer 
queues that work across greenlets, with the API similar to the classes found in 
the standard :mod:`Queue` and :class:`multiprocessing <multiprocessing.Queue>` 
modules.

A major difference is that queues in this module operate as channels when
initialized with *maxsize* of zero. In such case, both :meth:`Queue.empty`
and :meth:`Queue.full` return ``True`` and :meth:`Queue.put` always blocks until 
a call to :meth:`Queue.get` retrieves the item.

An interesting difference, made possible because of greenthreads, is 
that :meth:`Queue.qsize`, :meth:`Queue.empty`, and :meth:`Queue.full` *can* be 
used as indicators of whether the subsequent :meth:`Queue.get` 
or :meth:`Queue.put` will not block.  The new methods :meth:`Queue.getting` 
and :meth:`Queue.putting` report on the number of greenthreads blocking 
in :meth:`put <Queue.put>` or :meth:`get <Queue.get>` respectively.
"""

import sys
import heapq
import collections
import traceback
from Queue import Full, Empty


_NONE = object()
from eventlet.hubs import get_hub
from eventlet.greenthread import getcurrent
from eventlet.event import Event
from eventlet.timeout import Timeout

__all__ = ['Queue', 'PriorityQueue', 'LifoQueue', 'LightQueue', 'Full', 'Empty']

class Waiter(object): INDENT
    """A low level synchronization class.

    Wrapper around greenlet's ``switch()`` and ``throw()`` calls that makes them safe:

    * switching will occur only if the waiting greenlet is executing :meth:`wait`
      method currently. Otherwise, :meth:`switch` and :meth:`throw` are no-ops.
    * any error raised in the greenlet is handled inside :meth:`switch` and :meth:`throw`

    The :meth:`switch` and :meth:`throw` methods must only be called from the :class:`Hub` greenlet.
    The :meth:`wait` method must be called from a greenlet other than :class:`Hub`.
    """
    __slots__ = ['greenlet']

    def __init__(self): INDENT
        self.greenlet = None

DEDENT     def __repr__(self): INDENT
        if self.waiting: INDENT
            waiting = ' waiting'
DEDENT         else: INDENT
            waiting = ''
DEDENT         return '<%s at %s%s greenlet=%r>' % (type(self).__name__, hex(id(self)), waiting, self.greenlet)

DEDENT     def __str__(self): INDENT
        """
        >>> print Waiter()
        <Waiter greenlet=None>
        """
        if self.waiting: INDENT
            waiting = ' waiting'
DEDENT         else: INDENT
            waiting = ''
DEDENT         return '<%s%s greenlet=%s>' % (type(self).__name__, waiting, self.greenlet)

DEDENT     def __nonzero__(self): INDENT
        return self.greenlet is not None

DEDENT     @property
    def waiting(self): INDENT
        return self.greenlet is not None

DEDENT     def switch(self, value=None): INDENT
        """Wake up the greenlet that is calling wait() currently (if there is one).
        Can only be called from Hub's greenlet.
        """
        assert getcurrent() is get_hub().greenlet, "Can only use Waiter.switch method from the mainloop"
        if self.greenlet is not None: INDENT
            try: INDENT
                self.greenlet.switch(value)
DEDENT             except: INDENT
                traceback.print_exc()

DEDENT DEDENT DEDENT     def throw(self, *throw_args): INDENT
        """Make greenlet calling wait() wake up (if there is a wait()).
        Can only be called from Hub's greenlet.
        """
        assert getcurrent() is get_hub().greenlet, "Can only use Waiter.switch method from the mainloop"
        if self.greenlet is not None: INDENT
            try: INDENT
                self.greenlet.throw(*throw_args)
DEDENT             except: INDENT
                traceback.print_exc()

    # XXX should be renamed to get() ? and the whole class is called Receiver?
DEDENT DEDENT DEDENT     def wait(self): INDENT
        """Wait until switch() or throw() is called.
        """
        assert self.greenlet is None, 'This Waiter is already used by %r' % (self.greenlet, )
        self.greenlet = getcurrent()
        try: INDENT
            return get_hub().switch()
DEDENT         finally: INDENT
            self.greenlet = None


DEDENT DEDENT DEDENT class LightQueue(object): INDENT
    """
    This is a variant of Queue that behaves mostly like the standard 
    :class:`Queue`.  It differs by not supporting the 
    :meth:`task_done <Queue.task_done>` or :meth:`join <Queue.join>` methods,
    and is a little faster for not having that overhead.
    """

    def __init__(self, maxsize=None): INDENT
        if maxsize is None or maxsize < 0:  INDENT#None is not comparable in 3.x
            self.maxsize = None
DEDENT         else: INDENT
            self.maxsize = maxsize
DEDENT         self.getters = set()
        self.putters = set()
        self._event_unlock = None
        self._init(maxsize)

    # QQQ make maxsize into a property with setter that schedules unlock if necessary

DEDENT     def _init(self, maxsize): INDENT
        self.queue = collections.deque()

DEDENT     def _get(self): INDENT
        return self.queue.popleft()

DEDENT     def _put(self, item): INDENT
        self.queue.append(item)

DEDENT     def __repr__(self): INDENT
        return '<%s at %s %s>' % (type(self).__name__, hex(id(self)), self._format())

DEDENT     def __str__(self): INDENT
        return '<%s %s>' % (type(self).__name__, self._format())

DEDENT     def _format(self): INDENT
        result = 'maxsize=%r' % (self.maxsize, )
        if getattr(self, 'queue', None): INDENT
            result += ' queue=%r' % self.queue
DEDENT         if self.getters: INDENT
            result += ' getters[%s]' % len(self.getters)
DEDENT         if self.putters: INDENT
            result += ' putters[%s]' % len(self.putters)
DEDENT         if self._event_unlock is not None: INDENT
            result += ' unlocking'
DEDENT         return result

DEDENT     def qsize(self): INDENT
        """Return the size of the queue."""
        return len(self.queue)

DEDENT     def resize(self, size): INDENT
        """Resizes the queue's maximum size.

        If the size is increased, and there are putters waiting, they may be woken up."""
        if self.maxsize is not None and (size is None or size > self.maxsize):  INDENT# None is not comparable in 3.x
            # Maybe wake some stuff up
            self._schedule_unlock()
DEDENT         self.maxsize = size
        
DEDENT     def putting(self): INDENT
        """Returns the number of greenthreads that are blocked waiting to put
        items into the queue."""
        return len(self.putters)
        
DEDENT     def getting(self): INDENT
        """Returns the number of greenthreads that are blocked waiting on an 
        empty queue."""
        return len(self.getters)

DEDENT     def empty(self): INDENT
        """Return ``True`` if the queue is empty, ``False`` otherwise."""
        return not self.qsize()

DEDENT     def full(self): INDENT
        """Return ``True`` if the queue is full, ``False`` otherwise.

        ``Queue(None)`` is never full.
        """
        return self.maxsize is not None and self.qsize() >= self.maxsize # None is not comparable in 3.x

DEDENT     def put(self, item, block=True, timeout=None): INDENT
        """Put an item into the queue.

        If optional arg *block* is true and *timeout* is ``None`` (the default),
        block if necessary until a free slot is available. If *timeout* is
        a positive number, it blocks at most *timeout* seconds and raises
        the :class:`Full` exception if no free slot was available within that time.
        Otherwise (*block* is false), put an item on the queue if a free slot
        is immediately available, else raise the :class:`Full` exception (*timeout*
        is ignored in that case).
        """
        if self.maxsize is None or self.qsize() < self.maxsize: INDENT
            # there's a free slot, put an item right away
            self._put(item)
            if self.getters: INDENT
                self._schedule_unlock()
DEDENT DEDENT         elif not block and get_hub().greenlet is getcurrent(): INDENT
            # we're in the mainloop, so we cannot wait; we can switch() to other greenlets though
            # find a getter and deliver an item to it
            while self.getters: INDENT
                getter = self.getters.pop()
                if getter: INDENT
                    self._put(item)
                    item = self._get()
                    getter.switch(item)
                    return
DEDENT DEDENT             raise Full
DEDENT         elif block: INDENT
            waiter = ItemWaiter(item)
            self.putters.add(waiter)
            timeout = Timeout(timeout, Full)
            try: INDENT
                if self.getters: INDENT
                    self._schedule_unlock()
DEDENT                 result = waiter.wait()
                assert result is waiter, "Invalid switch into Queue.put: %r" % (result, )
                if waiter.item is not _NONE: INDENT
                    self._put(item)
DEDENT DEDENT             finally: INDENT
                timeout.cancel()
                self.putters.discard(waiter)
DEDENT DEDENT         else: INDENT
            raise Full

DEDENT DEDENT     def put_nowait(self, item): INDENT
        """Put an item into the queue without blocking.

        Only enqueue the item if a free slot is immediately available.
        Otherwise raise the :class:`Full` exception.
        """
        self.put(item, False)

DEDENT     def get(self, block=True, timeout=None): INDENT
        """Remove and return an item from the queue.

        If optional args *block* is true and *timeout* is ``None`` (the default),
        block if necessary until an item is available. If *timeout* is a positive number,
        it blocks at most *timeout* seconds and raises the :class:`Empty` exception
        if no item was available within that time. Otherwise (*block* is false), return
        an item if one is immediately available, else raise the :class:`Empty` exception
        (*timeout* is ignored in that case).
        """
        if self.qsize(): INDENT
            if self.putters: INDENT
                self._schedule_unlock()
DEDENT             return self._get()
DEDENT         elif not block and get_hub().greenlet is getcurrent(): INDENT
            # special case to make get_nowait() runnable in the mainloop greenlet
            # there are no items in the queue; try to fix the situation by unlocking putters
            while self.putters: INDENT
                putter = self.putters.pop()
                if putter: INDENT
                    putter.switch(putter)
                    if self.qsize(): INDENT
                        return self._get()
DEDENT DEDENT DEDENT             raise Empty
DEDENT         elif block: INDENT
            waiter = Waiter()
            timeout = Timeout(timeout, Empty)
            try: INDENT
                self.getters.add(waiter)
                if self.putters: INDENT
                    self._schedule_unlock()
DEDENT                 return waiter.wait()
DEDENT             finally: INDENT
                self.getters.discard(waiter)
                timeout.cancel()
DEDENT DEDENT         else: INDENT
            raise Empty

DEDENT DEDENT     def get_nowait(self): INDENT
        """Remove and return an item from the queue without blocking.

        Only get an item if one is immediately available. Otherwise
        raise the :class:`Empty` exception.
        """
        return self.get(False)

DEDENT     def _unlock(self): INDENT
        try: INDENT
            while True: INDENT
                if self.qsize() and self.getters: INDENT
                    getter = self.getters.pop()
                    if getter: INDENT
                        try: INDENT
                            item = self._get()
DEDENT                         except: INDENT
                            getter.throw(*sys.exc_info())
DEDENT                         else: INDENT
                            getter.switch(item)
DEDENT DEDENT DEDENT                 elif self.putters and self.getters: INDENT
                    putter = self.putters.pop()
                    if putter: INDENT
                        getter = self.getters.pop()
                        if getter: INDENT
                            item = putter.item
                            putter.item = _NONE # this makes greenlet calling put() not to call _put() again
                            self._put(item)
                            item = self._get()
                            getter.switch(item)
                            putter.switch(putter)
DEDENT                         else: INDENT
                            self.putters.add(putter)
DEDENT DEDENT DEDENT                 elif self.putters and (self.getters or self.maxsize is None or self.qsize() < self.maxsize): INDENT
                    putter = self.putters.pop()
                    putter.switch(putter)
DEDENT                 else: INDENT
                    break
DEDENT DEDENT DEDENT         finally: INDENT
            self._event_unlock = None # QQQ maybe it's possible to obtain this info from libevent?
            # i.e. whether this event is pending _OR_ currently executing
        # testcase: 2 greenlets: while True: q.put(q.get()) - nothing else has a change to execute
        # to avoid this, schedule unlock with timer(0, ...) once in a while

DEDENT DEDENT     def _schedule_unlock(self): INDENT
        if self._event_unlock is None: INDENT
            self._event_unlock = get_hub().schedule_call_global(0, self._unlock)


DEDENT DEDENT DEDENT class ItemWaiter(Waiter): INDENT
    __slots__ = ['item']

    def __init__(self, item): INDENT
        Waiter.__init__(self)
        self.item = item
        

DEDENT DEDENT class Queue(LightQueue): INDENT
    '''Create a queue object with a given maximum size.

    If *maxsize* is less than zero or ``None``, the queue size is infinite.

    ``Queue(0)`` is a channel, that is, its :meth:`put` method always blocks 
    until the item is delivered. (This is unlike the standard :class:`Queue`, 
    where 0 means infinite size).
    
    In all other respects, this Queue class resembled the standard library,
    :class:`Queue`.
    '''
    def __init__(self, maxsize=None): INDENT
        LightQueue.__init__(self, maxsize)
        self.unfinished_tasks = 0
        self._cond = Event()

DEDENT     def _format(self): INDENT
        result = LightQueue._format(self)
        if self.unfinished_tasks: INDENT
            result += ' tasks=%s _cond=%s' % (self.unfinished_tasks, self._cond)
DEDENT         return result

DEDENT     def _put(self, item): INDENT
        LightQueue._put(self, item)
        self._put_bookkeeping()

DEDENT     def _put_bookkeeping(self): INDENT
        self.unfinished_tasks += 1
        if self._cond.ready(): INDENT
            self._cond.reset()

DEDENT DEDENT     def task_done(self): INDENT
        '''Indicate that a formerly enqueued task is complete. Used by queue consumer threads.
        For each :meth:`get <Queue.get>` used to fetch a task, a subsequent call to :meth:`task_done` tells the queue
        that the processing on the task is complete.

        If a :meth:`join` is currently blocking, it will resume when all items have been processed
        (meaning that a :meth:`task_done` call was received for every item that had been
        :meth:`put <Queue.put>` into the queue).

        Raises a :exc:`ValueError` if called more times than there were items placed in the queue.
        '''
        
        if self.unfinished_tasks <= 0: INDENT
            raise ValueError('task_done() called too many times')
DEDENT         self.unfinished_tasks -= 1
        if self.unfinished_tasks == 0: INDENT
            self._cond.send(None)

DEDENT DEDENT     def join(self): INDENT
        '''Block until all items in the queue have been gotten and processed.

        The count of unfinished tasks goes up whenever an item is added to the queue.
        The count goes down whenever a consumer thread calls :meth:`task_done` to indicate
        that the item was retrieved and all work on it is complete. When the count of
        unfinished tasks drops to zero, :meth:`join` unblocks.
        '''
        self._cond.wait()


DEDENT DEDENT class PriorityQueue(Queue): INDENT
    '''A subclass of :class:`Queue` that retrieves entries in priority order (lowest first).

    Entries are typically tuples of the form: ``(priority number, data)``.
    '''

    def _init(self, maxsize): INDENT
        self.queue = []

DEDENT     def _put(self, item, heappush=heapq.heappush): INDENT
        heappush(self.queue, item)
        self._put_bookkeeping()

DEDENT     def _get(self, heappop=heapq.heappop): INDENT
        return heappop(self.queue)


DEDENT DEDENT class LifoQueue(Queue): INDENT
    '''A subclass of :class:`Queue` that retrieves most recently added entries first.'''

    def _init(self, maxsize): INDENT
        self.queue = []

DEDENT     def _put(self, item): INDENT
        self.queue.append(item)
        self._put_bookkeeping()

DEDENT     def _get(self): INDENT
        return self.queue.pop()

DEDENT DEDENT 
