class Node: INDENT
    value = None
    next  = None
    
    def put(self,x): INDENT
        self.next = x
        return
    
DEDENT     def get(self): INDENT
        return self.value
        
DEDENT     def isempty(self): INDENT
        return (self.value==None)
        
DEDENT     def __str__(self): INDENT
        return str(self.value)
    
DEDENT DEDENT class Queue: INDENT
    first = None
    last = None
    length = 0
    
    def put(self,x): INDENT
        self.length+=1
        
        p = Node()
        p.value = x
        
        if self.first==None: INDENT
            self.first = p
            self.last = p
DEDENT         else: INDENT
            self.last.next = p
            self.last = p
DEDENT         return
    
DEDENT     def peek(self): INDENT
        return self.first.value

DEDENT     def get(self): INDENT
        self.length-=1
        if(self.isempty()): INDENT
            raise Exception
DEDENT         getthis = self.first.value # get the value to return first
        self.first = self.first.next #set the next node as first
        return getthis
        
DEDENT     def isempty(self): INDENT
        return (self.first==None)
        
DEDENT     def putQueue(self,q): INDENT
        while(not q.isempty()): INDENT
            self.put(q.get())
        
DEDENT         return
        

DEDENT     def __eq__(self, m): INDENT
        return self.retVector() == m.retVector()

DEDENT     def __neq__(self, m): INDENT
        return self.retVector() != m.retVector()


DEDENT     def getVector(self):  INDENT#gets all elements but destructive since it empties the queue
        vector = []
        while(not self.isempty()): INDENT
            vector += [self.get()]
DEDENT         return vector
        
DEDENT     def retVector(self):  INDENT
        vector = self.getVector()
        self.putVector(vector) #since all nodes are taken away we have to put them back before returning
        return vector
    
DEDENT     def putVector(self,vector): INDENT
        for i in range(len(vector)): INDENT
            self.put(vector[i])   
        
DEDENT DEDENT     def __init__(self,vector = []): INDENT
        for i in range(len(vector)): INDENT
            self.put(vector[i])
DEDENT         return
    
DEDENT     def __len__(self): INDENT
        return self.length
    


DEDENT     def __str__(self): INDENT
        str_values = ""
        values = self.retVector()
        for i in range(len(values)): INDENT
            str_values += "%s | "%values[i]
        
DEDENT         return "Queue=| %s"%str_values

DEDENT     def flush(self): INDENT
        while(not self.isempty()): INDENT
            self.get()

DEDENT DEDENT     def splitat(self,i): INDENT
    
        vector = self.retVector()
        
        if(len(vector)<i): INDENT
            raise ValueError
            
DEDENT         self.flush() # empty the self-queue since
            
        return Queue(vector[0:i]),Queue(vector[i:len(vector)])
    
DEDENT     def splitInHalf(self):  INDENT#only for even length arrays
        
        if(len(self)%2==1): INDENT
            raise ValueError

DEDENT         return self.splitat(len(self)/2)
        
        
        


DEDENT DEDENT 
