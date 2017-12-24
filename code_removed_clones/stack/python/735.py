# A stack class

class Stack(object): INDENT
  items = [ ]
  
  def __init__(self): INDENT
    self.items = [ ]
        
  ##############################################
  # Methods which change the value of the stack
  ##############################################
  
DEDENT   def push(self, x): INDENT
    self.items.append(x)
    
DEDENT   def pushList(self, L): INDENT
    for item in L: INDENT
      self.push(item)
  
DEDENT DEDENT   def pop(self): INDENT
    k = len(self.items) - 1
    value = self.items[k]
    self.items = self.items[:k]
    return value
    
  ##############################################
   # Methods which read the stack
  ##############################################
    
DEDENT   def peek(self, j): INDENT
    k = len(self.items) - 1
    value = self.items[k-j]
    return value
   
DEDENT   def index(self, x): INDENT
    if x in self.items: INDENT
      return self.items.index(x)
DEDENT     else: INDENT
      return -1
      
DEDENT DEDENT   def count(self): INDENT
    return len(self.items)
    
DEDENT   def display(self): INDENT
    k = 0
    for item in self.items: INDENT
          print "  "+`k`+":", item
          k = k + 1

  ##############################################
  
DEDENT DEDENT DEDENT 
