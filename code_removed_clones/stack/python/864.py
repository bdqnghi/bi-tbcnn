class ListItem: INDENT
        next = None
        val = 0

DEDENT class Stack: INDENT
        top = None

        def push(self, val): INDENT
                elt = ListItem()
                elt.val = val
                elt.next = self.top
                self.top = elt

DEDENT         def pop(self): INDENT
                if self.top != None: INDENT
                        tmp = self.top
                        self.top = tmp.next
                        return tmp
DEDENT                 else: INDENT
                        return None


DEDENT DEDENT DEDENT stack = Stack()
stack.push(1)
print stack.pop().val
print stack.pop()

stack.push(2)
stack.push(3)

print stack.pop().val
print stack.pop().val
