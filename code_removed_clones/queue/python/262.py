# util/queue.py
# Copyright (C) 2005-2012 the SQLAlchemy authors and contributors <see AUTHORS file>
#
# This module is part of SQLAlchemy and is released under
# the MIT License: http://www.opensource.org/licenses/mit-license.php

"""An adaptation of Py2.3/2.4's Queue module which supports reentrant
behavior, using RLock instead of Lock for its mutex object.

This is to support the connection pool's usage of weakref callbacks to return
connections to the underlying Queue, which can in extremely
rare cases be invoked within the ``get()`` method of the Queue itself,
producing a ``put()`` inside the ``get()`` and therefore a reentrant
condition."""

from collections import deque
from time import time as _time
from sqlalchemy.util import threading
import sys

if sys.version_info < (2, 6): INDENT
    def notify_all(condition): INDENT
        condition.notify()
DEDENT DEDENT else: INDENT
    def notify_all(condition): INDENT
        condition.notify_all()


DEDENT DEDENT __all__ = ['Empty', 'Full', 'Queue']

class Empty(Exception): INDENT
    "Exception raised by Queue.get(block=0)/get_nowait()."

    pass

DEDENT class Full(Exception): INDENT
    "Exception raised by Queue.put(block=0)/put_nowait()."

    pass

DEDENT class SAAbort(Exception): INDENT
    "Special SQLA exception to abort waiting"
    def __init__(self, context): INDENT
        self.context = context

DEDENT DEDENT class Queue: INDENT
    def __init__(self, maxsize=0): INDENT
        """Initialize a queue object with a given maximum size.

        If `maxsize` is <= 0, the queue size is infinite.
        """

        self._init(maxsize)
        # mutex must be held whenever the queue is mutating.  All methods
        # that acquire mutex must release it before returning.  mutex
        # is shared between the two conditions, so acquiring and
        # releasing the conditions also acquires and releases mutex.
        self.mutex = threading.RLock()
        # Notify not_empty whenever an item is added to the queue; a
        # thread waiting to get is notified then.
        self.not_empty = threading.Condition(self.mutex)
        # Notify not_full whenever an item is removed from the queue;
        # a thread waiting to put is notified then.
        self.not_full = threading.Condition(self.mutex)

        # when this is set, SAAbort is raised within get().
        self._sqla_abort_context = False

DEDENT     def qsize(self): INDENT
        """Return the approximate size of the queue (not reliable!)."""

        self.mutex.acquire()
        n = self._qsize()
        self.mutex.release()
        return n

DEDENT     def empty(self): INDENT
        """Return True if the queue is empty, False otherwise (not
        reliable!)."""

        self.mutex.acquire()
        n = self._empty()
        self.mutex.release()
        return n

DEDENT     def full(self): INDENT
        """Return True if the queue is full, False otherwise (not
        reliable!)."""

        self.mutex.acquire()
        n = self._full()
        self.mutex.release()
        return n

DEDENT     def put(self, item, block=True, timeout=None): INDENT
        """Put an item into the queue.

        If optional args `block` is True and `timeout` is None (the
        default), block if necessary until a free slot is
        available. If `timeout` is a positive number, it blocks at
        most `timeout` seconds and raises the ``Full`` exception if no
        free slot was available within that time.  Otherwise (`block`
        is false), put an item on the queue if a free slot is
        immediately available, else raise the ``Full`` exception
        (`timeout` is ignored in that case).
        """

        self.not_full.acquire()
        try: INDENT
            if not block: INDENT
                if self._full(): INDENT
                    raise Full
DEDENT DEDENT             elif timeout is None: INDENT
                while self._full(): INDENT
                    self.not_full.wait()
DEDENT DEDENT             else: INDENT
                if timeout < 0: INDENT
                    raise ValueError("'timeout' must be a positive number")
DEDENT                 endtime = _time() + timeout
                while self._full(): INDENT
                    remaining = endtime - _time()
                    if remaining <= 0.0: INDENT
                        raise Full
DEDENT                     self.not_full.wait(remaining)
DEDENT DEDENT             self._put(item)
            self.not_empty.notify()
DEDENT         finally: INDENT
            self.not_full.release()

DEDENT DEDENT     def put_nowait(self, item): INDENT
        """Put an item into the queue without blocking.

        Only enqueue the item if a free slot is immediately available.
        Otherwise raise the ``Full`` exception.
        """
        return self.put(item, False)

DEDENT     def get(self, block=True, timeout=None): INDENT
        """Remove and return an item from the queue.

        If optional args `block` is True and `timeout` is None (the
        default), block if necessary until an item is available. If
        `timeout` is a positive number, it blocks at most `timeout`
        seconds and raises the ``Empty`` exception if no item was
        available within that time.  Otherwise (`block` is false),
        return an item if one is immediately available, else raise the
        ``Empty`` exception (`timeout` is ignored in that case).
        """

        self.not_empty.acquire()
        try: INDENT
            if not block: INDENT
                if self._empty(): INDENT
                    raise Empty
DEDENT DEDENT             elif timeout is None: INDENT
                while self._empty(): INDENT
                    self.not_empty.wait()
                    if self._sqla_abort_context: INDENT
                        raise SAAbort(self._sqla_abort_context)
DEDENT DEDENT DEDENT             else: INDENT
                if timeout < 0: INDENT
                    raise ValueError("'timeout' must be a positive number")
DEDENT                 endtime = _time() + timeout
                while self._empty(): INDENT
                    remaining = endtime - _time()
                    if remaining <= 0.0: INDENT
                        raise Empty
DEDENT                     self.not_empty.wait(remaining)
                    if self._sqla_abort_context: INDENT
                        raise SAAbort(self._sqla_abort_context)
DEDENT DEDENT DEDENT             item = self._get()
            self.not_full.notify()
            return item
DEDENT         finally: INDENT
            self.not_empty.release()

DEDENT DEDENT     def abort(self, context): INDENT
        """Issue an 'abort', will force any thread waiting on get()
        to stop waiting and raise SAAbort.

        """
        self._sqla_abort_context = context
        if not self.not_full.acquire(False): INDENT
            return
DEDENT         try: INDENT
            notify_all(self.not_empty)
DEDENT         finally: INDENT
            self.not_full.release()

DEDENT DEDENT     def get_nowait(self): INDENT
        """Remove and return an item from the queue without blocking.

        Only get an item if one is immediately available. Otherwise
        raise the ``Empty`` exception.
        """

        return self.get(False)

    # Override these methods to implement other queue organizations
    # (e.g. stack or priority queue).
    # These will only be called with appropriate locks held

    # Initialize the queue representation
DEDENT     def _init(self, maxsize): INDENT
        self.maxsize = maxsize
        self.queue = deque()

DEDENT     def _qsize(self): INDENT
        return len(self.queue)

    # Check whether the queue is empty
DEDENT     def _empty(self): INDENT
        return not self.queue

    # Check whether the queue is full
DEDENT     def _full(self): INDENT
        return self.maxsize > 0 and len(self.queue) == self.maxsize

    # Put a new item in the queue
DEDENT     def _put(self, item): INDENT
        self.queue.append(item)

    # Get an item from the queue
DEDENT     def _get(self): INDENT
        return self.queue.popleft()
DEDENT DEDENT 
