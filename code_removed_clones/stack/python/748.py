# -*- coding: utf-8 -*-
#
#    Copyright © 2012 Simon Forman
#
#    This file is part of Pigeon Computer.
#
#    Pigeon Computer is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Pigeon Computer is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Pigeon Computer.  If not, see <http://www.gnu.org/licenses/>.
#
'''
Stack
=================================

Tuple-based persistent stack.

This is too simple to document.  It's almost too simple to implement.
'''


def push(stack, *items): INDENT
    '''Push arguments onto a stack.'''
    for item in items: INDENT
        stack = item, stack # push
DEDENT     return stack


DEDENT def pop(stack, number): INDENT
    '''Pop number arguments from stack.'''
    for _ in range(number): INDENT
        item, stack = stack # pop
        yield item
DEDENT     yield stack


DEDENT def iterStack(stack): INDENT
    '''Iterate through the items on the stack.'''
    while stack: INDENT
        item, stack = stack
        yield item


DEDENT DEDENT def lenStack(stack): INDENT
    '''Return the number of items on the stack.'''
    return sum(1 for _ in iterStack(stack))


DEDENT def pick_(stack, n): INDENT
    '''
    Find the nth item on the stack and duplicate it to TOS. (Pick with
    zero is the same as "dup".)
    '''
    if n < 0: INDENT
        raise ValueError
DEDENT     s = stack
    while True: INDENT
        try: INDENT
            item, s = s
DEDENT         except ValueError: INDENT
            raise IndexError
DEDENT         n -= 1
        if n < 0: INDENT
            break
DEDENT DEDENT     return item, stack

DEDENT 
