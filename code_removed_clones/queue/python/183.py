"""A multi-producer, multi-consumer queue."""

from time import time as _time
try: INDENT
    import threading as _threading
DEDENT except ImportError: INDENT
    import dummy_threading as _threading
DEDENT from collections import deque
import heapq

__all__ = ['Empty', 'Full', 'Queue', 'PriorityQueue', 'LifoQueue']

class Empty(Exception): INDENT
    "Exception raised by Queue.get(block=0)/get_nowait()."
    pass

DEDENT class Full(Exception): INDENT
    "Exception raised by Queue.put(block=0)/put_nowait()."
    pass

DEDENT class Queue: INDENT
    """Create a queue object with a given maximum size.

    If maxsize is <= 0, the queue size is infinite.
    """
    def __init__(self, maxsize=0): INDENT
        self.maxsize = maxsize
        self._init(maxsize)
        # mutex must be held whenever the queue is mutating.  All methods
        # that acquire mutex must release it before returning.  mutex
        # is shared between the three conditions, so acquiring and
        # releasing the conditions also acquires and releases mutex.
        self.mutex = _threading.Lock()
        # Notify not_empty whenever an item is added to the queue; a
        # thread waiting to get is notified then.
        self.not_empty = _threading.Condition(self.mutex)
        # Notify not_full whenever an item is removed from the queue;
        # a thread waiting to put is notified then.
        self.not_full = _threading.Condition(self.mutex)
        # Notify all_tasks_done whenever the number of unfinished tasks
        # drops to zero; thread waiting to join() is notified to resume
        self.all_tasks_done = _threading.Condition(self.mutex)
        self.unfinished_tasks = 0

DEDENT     def task_done(self): INDENT
        """Indicate that a formerly enqueued task is complete.

        Used by Queue consumer threads.  For each get() used to fetch a task,
        a subsequent call to task_done() tells the queue that the processing
        on the task is complete.

        If a join() is currently blocking, it will resume when all items
        have been processed (meaning that a task_done() call was received
        for every item that had been put() into the queue).

        Raises a ValueError if called more times than there were items
        placed in the queue.
        """
        self.all_tasks_done.acquire()
        try: INDENT
            unfinished = self.unfinished_tasks - 1
            if unfinished <= 0: INDENT
                if unfinished < 0: INDENT
                    raise ValueError('task_done() called too many times')
DEDENT                 self.all_tasks_done.notify_all()
DEDENT             self.unfinished_tasks = unfinished
DEDENT         finally: INDENT
            self.all_tasks_done.release()

DEDENT DEDENT     def join(self): INDENT
        """Blocks until all items in the Queue have been gotten and processed.

        The count of unfinished tasks goes up whenever an item is added to the
        queue. The count goes down whenever a consumer thread calls task_done()
        to indicate the item was retrieved and all work on it is complete.

        When the count of unfinished tasks drops to zero, join() unblocks.
        """
        self.all_tasks_done.acquire()
        try: INDENT
            while self.unfinished_tasks: INDENT
                self.all_tasks_done.wait()
DEDENT DEDENT         finally: INDENT
            self.all_tasks_done.release()

DEDENT DEDENT     def qsize(self): INDENT
        """Return the approximate size of the queue (not reliable!)."""
        self.mutex.acquire()
        n = self._qsize()
        self.mutex.release()
        return n

DEDENT     def empty(self): INDENT
        """Return True if the queue is empty, False otherwise (not reliable!)."""
        self.mutex.acquire()
        n = not self._qsize()
        self.mutex.release()
        return n

DEDENT     def full(self): INDENT
        """Return True if the queue is full, False otherwise (not reliable!)."""
        self.mutex.acquire()
        n = 0 < self.maxsize == self._qsize()
        self.mutex.release()
        return n

DEDENT     def put(self, item, block=True, timeout=None): INDENT
        """Put an item into the queue.

        If optional args 'block' is true and 'timeout' is None (the default),
        block if necessary until a free slot is available. If 'timeout' is
        a positive number, it blocks at most 'timeout' seconds and raises
        the Full exception if no free slot was available within that time.
        Otherwise ('block' is false), put an item on the queue if a free slot
        is immediately available, else raise the Full exception ('timeout'
        is ignored in that case).
        """
        self.not_full.acquire()
        try: INDENT
            if self.maxsize > 0: INDENT
                if not block: INDENT
                    if self._qsize() == self.maxsize: INDENT
                        raise Full
DEDENT DEDENT                 elif timeout is None: INDENT
                    while self._qsize() == self.maxsize: INDENT
                        self.not_full.wait()
DEDENT DEDENT                 elif timeout < 0: INDENT
                    raise ValueError("'timeout' must be a positive number")
DEDENT                 else: INDENT
                    endtime = _time() + timeout
                    while self._qsize() == self.maxsize: INDENT
                        remaining = endtime - _time()
                        if remaining <= 0.0: INDENT
                            raise Full
DEDENT                         self.not_full.wait(remaining)
DEDENT DEDENT DEDENT             self._put(item)
            self.unfinished_tasks += 1
            self.not_empty.notify()
DEDENT         finally: INDENT
            self.not_full.release()

DEDENT DEDENT     def put_nowait(self, item): INDENT
        """Put an item into the queue without blocking.

        Only enqueue the item if a free slot is immediately available.
        Otherwise raise the Full exception.
        """
        return self.put(item, False)

DEDENT     def get(self, block=True, timeout=None): INDENT
        """Remove and return an item from the queue.

        If optional args 'block' is true and 'timeout' is None (the default),
        block if necessary until an item is available. If 'timeout' is
        a positive number, it blocks at most 'timeout' seconds and raises
        the Empty exception if no item was available within that time.
        Otherwise ('block' is false), return an item if one is immediately
        available, else raise the Empty exception ('timeout' is ignored
        in that case).
        """
        self.not_empty.acquire()
        try: INDENT
            if not block: INDENT
                if not self._qsize(): INDENT
                    raise Empty
DEDENT DEDENT             elif timeout is None: INDENT
                while not self._qsize(): INDENT
                    self.not_empty.wait()
DEDENT DEDENT             elif timeout < 0: INDENT
                raise ValueError("'timeout' must be a positive number")
DEDENT             else: INDENT
                endtime = _time() + timeout
                while not self._qsize(): INDENT
                    remaining = endtime - _time()
                    if remaining <= 0.0: INDENT
                        raise Empty
DEDENT                     self.not_empty.wait(remaining)
DEDENT DEDENT             item = self._get()
            self.not_full.notify()
            return item
DEDENT         finally: INDENT
            self.not_empty.release()

DEDENT DEDENT     def get_nowait(self): INDENT
        """Remove and return an item from the queue without blocking.

        Only get an item if one is immediately available. Otherwise
        raise the Empty exception.
        """
        return self.get(False)

    # Override these methods to implement other queue organizations
    # (e.g. stack or priority queue).
    # These will only be called with appropriate locks held

    # Initialize the queue representation
DEDENT     def _init(self, maxsize): INDENT
        self.queue = deque()

DEDENT     def _qsize(self, len=len): INDENT
        return len(self.queue)

    # Put a new item in the queue
DEDENT     def _put(self, item): INDENT
        self.queue.append(item)

    # Get an item from the queue
DEDENT     def _get(self): INDENT
        return self.queue.popleft()


DEDENT DEDENT class PriorityQueue(Queue): INDENT
    '''Variant of Queue that retrieves open entries in priority order (lowest first).

    Entries are typically tuples of the form:  (priority number, data).
    '''

    def _init(self, maxsize): INDENT
        self.queue = []

DEDENT     def _qsize(self, len=len): INDENT
        return len(self.queue)

DEDENT     def _put(self, item, heappush=heapq.heappush): INDENT
        heappush(self.queue, item)

DEDENT     def _get(self, heappop=heapq.heappop): INDENT
        return heappop(self.queue)


DEDENT DEDENT class LifoQueue(Queue): INDENT
    '''Variant of Queue that retrieves most recently added entries first.'''

    def _init(self, maxsize): INDENT
        self.queue = []

DEDENT     def _qsize(self, len=len): INDENT
        return len(self.queue)

DEDENT     def _put(self, item): INDENT
        self.queue.append(item)

DEDENT     def _get(self): INDENT
        return self.queue.pop()
DEDENT DEDENT 
