#!/usr/bin/env python

"""
    Stack Implementation Solution: v0.4
      
    The specs say we'll be handling integers. There's no need to make this
    stack implementation that narrow. Making it more generic and robust. It
    will handle any object.

    Version History:
        v0.1: Works according to spec.
        v0.2: CodeEval passes a blank line in input. They imply that there
              will be no blanks and do not state how to handle them. Fixed.
        v0.3: Performed some code cleaning.
        v0.4: Code and documentation refactoring.


    ========================================
    Copyright 2012, 2013,  Jamie Thomas Duby
    ========================================

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
  
    http://www.apache.org/licenses/LICENSE-2.0
 
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
"""

import sys

class Stack(object): INDENT
    def __init__(self): INDENT
        self._stack = []
DEDENT     def __len__(self): INDENT
        return(len(self._stack))
DEDENT     def push(self, obj): INDENT
        """Pushes an object onto the stack.
        """
        self._stack.append(obj)
DEDENT     def pop(self): INDENT
        """Raises StackEmpty instead of returning None so that None can be
        pushed onto the stack.
        """
        try: INDENT
            return self._stack.pop()
DEDENT         except IndexError: INDENT
            raise StackEmpty
DEDENT DEDENT     def empty(self): INDENT
        """Checks if the stack is empty.
        """
        if len(self._stack) == 0: INDENT
            return True
DEDENT         else: INDENT
            return False

DEDENT DEDENT DEDENT class StackEmpty(BaseException): INDENT
    """Inheriting from BaseException because this isn't really an error."""
    pass
        
DEDENT def parse_line(line): INDENT
    """Takes a line of space seperated values, returns the values in a list.
    """
    line_list = line.strip().split(' ')
    return line_list

DEDENT def batch_push(stack, items): INDENT
    """Pushes the objects in the items list onto the stack."""
    for i in items: INDENT
        stack.push(i)

DEDENT DEDENT def alt_print(stack): INDENT
    """Pops the items from a stack and returns a string containing every other
    item, starting with the first, seperated by spaces. e.g.

        [1, 2, 3, 4] --> "1 3"
    """
    alt = True
    out = ''
    while not stack.empty(): INDENT
        n = stack.pop()
        if alt: INDENT
            out = out + n
            alt = False
DEDENT         else: INDENT
            out = out + ' '
            alt = True
DEDENT DEDENT     print(out.strip())
 
DEDENT if __name__ == '__main__': INDENT
    with open(sys.argv[1], 'r') as infile: INDENT
        s = Stack()
        for line in infile: INDENT
            items = parse_line(line)
            batch_push(s, items)
            alt_print(s)
DEDENT DEDENT     sys.exit(0)
DEDENT 
