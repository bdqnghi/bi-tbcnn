
class Stack: INDENT
    def __init__(self): INDENT
        self.items = []

DEDENT     def push(self,item): INDENT
        self.items.append(item)

DEDENT     def pop(self): INDENT
        return self.items.pop()

DEDENT     def peek(self): INDENT
        return self.items[-1]

DEDENT     def isEmpty(self): INDENT
        #return True if self.items else False
        return self.items == []

DEDENT     def size(self): INDENT
        return len(self.items)

DEDENT DEDENT class OtherStack(Stack): INDENT
    def push(self,item): INDENT
        self.items.insert(0,item)

DEDENT     def pop(self): INDENT
        return self.items.pop(0)

DEDENT     def peek(self): INDENT
        return self.items[0]


DEDENT DEDENT def revstring(s1): INDENT
    stack = Stack()
    s2 = ''
    for c in s1: INDENT
        stack.push(c)
DEDENT     while not stack.isEmpty(): INDENT
        s2 += stack.pop()
DEDENT     return s2


DEDENT def palindrome(s1): INDENT
    stack = Stack()
    s2 = ''
    for c in s1: INDENT
        stack.push(c)
DEDENT     while not stack.isEmpty(): INDENT
        s2 += stack.pop()
DEDENT     return s1==s2

DEDENT if __name__ == '__main__': INDENT
    print revstring('rar.lauD.piRDVD.divX.01c1l1S.0d.3l4V.0d.s4t4r1P/n45jd5hc9/selif/moc.seliftisoped//:ptth')
DEDENT 
