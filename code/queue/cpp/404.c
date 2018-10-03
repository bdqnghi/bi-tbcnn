/*
 * Copyright 2007-2009 M.Mueller
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *    3. The name of the author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "queue.h"
#include <debuglog.h>


qentry* queue_base::Read()
{ DEBUGLOG(("queue_base(%p)::Read()\n", this));
  for(;;)
  { EvEmpty.Wait();
    Mutex::Lock lock(Mtx);
    qentry* qp = Head;
    if (qp) // The event alone is not reliable.
    { Head = qp->Next;
      if (!Head)
        Tail = NULL;
      DEBUGLOG(("queue_base::Read() - %p\n", qp));
      return qp;
    }
    EvEmpty.Reset();
  }
}

void queue_base::Write(qentry* entry)
{ DEBUGLOG(("queue_base(%p)::Write(%p)\n", this, entry));
  entry->Next = NULL;
  Mutex::Lock lock(Mtx);
  if (Tail)
    Tail->Next = entry;
   else
    Head = entry;
  Tail = entry;
  EvEmpty.Set(); // signal readers
}

void queue_base::Write(qentry* entry, qentry* after)
{ DEBUGLOG(("queue_base(%p)::Write(%p, %p)\n", this, entry, after));
  ASSERT(entry);
  Mutex::Lock lock(Mtx);
  // insert
  qentry*& qp = after ? after->Next : Head;
  entry->Next = qp;
  qp = entry;
  // update Tail
  if (Tail == after)
    Tail = entry;
  EvEmpty.Set(); // signal readers
}

void queue_base::WriteFront(qentry* entry)
{ DEBUGLOG(("queue_base(%p)::WriteFront(%p)\n", this, entry));
  ASSERT(entry);
  Mutex::Lock lock(Mtx);
  entry->Next = Head;
  if (!Head)
    Tail = entry;
  Head = entry;
  EvEmpty.Set(); // signal readers
}

qentry* queue_base::Purge()
{ DEBUGLOG(("queue_base(%p)::Purge() - %p, %p\n", this, Head, Tail));
  Mutex::Lock lock(Mtx);
  Tail = NULL;
  qentry* rhead = Head;
  Head = NULL;
  return rhead;
}

bool queue_base::ForEach(bool (*action)(const qentry* entry, void* arg), void* arg)
{ DEBUGLOG(("queue_base(%p)::ForEach(%p, %p) - %p\n", this, action, arg, Head));
  Mutex::Lock lock(Mtx);
  for (const qentry* ep = Head; ep; ep = ep->Next)
    if (!action(ep, arg))
      return false;
  return true;
}


