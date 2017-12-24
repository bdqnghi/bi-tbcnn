"""
pystoch.utilities.stack
-----------------------

"""

class Stack(object): INDENT

    def __init__(self, stacktype): INDENT
        if not isinstance(stacktype, type): INDENT
            raise ValueError, "stacktype must be a type"
        
DEDENT         self.stack = []
        self.stacktype = stacktype

DEDENT     def pop(self): INDENT
        if len(self.stack) == 0: INDENT
            raise IndexError, "pop from empty stack"
DEDENT         return self.stack.pop()

DEDENT     def push(self, elmt): INDENT
        if not isinstance(elmt, self.stacktype): INDENT
            raise ValueError("elmt must be a %s" % self.stacktype)
DEDENT         self.stack.append(elmt)

DEDENT     def set(self, val): INDENT
        if not isinstance(val, self.stacktype): INDENT
            raise ValueError("val must be a %s" % self.stacktype)
DEDENT         if len(self.stack) == 0: INDENT
            raise IndexError, "setting empty stack"
DEDENT         self.stack[-1] = val

DEDENT     def increment(self): INDENT
        if len(self.stack) == 0: INDENT
            raise IndexError, "incrementing empty stack"
DEDENT         self.stack[-1] += 1

DEDENT     def decrement(self): INDENT
        if len(self.stack) == 0: INDENT
            raise IndexError, "decrementing empty stack"
DEDENT         self.stack[-1] -= 1

DEDENT     def peek(self): INDENT
        if len(self.stack) > 0: INDENT
            return self.stack[-1]
DEDENT         return 'null'

DEDENT     def __hash__(self): INDENT
        stack = [str(item) for item in self.stack]
        return hash(''.join(stack))

DEDENT     def __str__(self): INDENT
        string = []
        previtem = None
        numprev = 0
        for i in xrange(len(self.stack)): INDENT
            item = self.stack[len(self.stack)-i-1]
            if item != previtem: INDENT
                if numprev > 1: INDENT
                    string[-1] += "*%s" % numprev
DEDENT                 string.insert(0, str(item))
                numprev = 1
DEDENT             else: INDENT
                numprev += 1

DEDENT             previtem = item

DEDENT         return ','.join(string)

DEDENT     def __repr__(self): INDENT
        return "<Stack %s>" % self.__str__()

DEDENT DEDENT class IntegerStack(Stack): INDENT
    def __init__(self): INDENT
        super(IntegerStack, self).__init__(int)

DEDENT DEDENT class StringStack(Stack): INDENT
    def __init__(self): INDENT
        super(StringStack, self).__init__(str)
DEDENT DEDENT 
