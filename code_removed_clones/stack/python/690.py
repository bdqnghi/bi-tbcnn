from Cell import Cell

class StackStack(object): INDENT
        def __init__( self ): INDENT
                #self.stacks = [ Stack() ]
                self.stacks = [ [] ]

DEDENT         def toss( self ):  INDENT# top of stack stack
                return self.stacks[-1]

DEDENT         def soss( self ):  INDENT# second of stack stack
                if len(self.stacks) < 2: return []
                return self.stacks[-2]
        
DEDENT         def begin( self, n ): INDENT
                '''Copy top n to new stack and push stack to new toss.
			Negative n backfills soss with 0's.
		'''
                s = []
                n = n.as_int()
                if n > 0: INDENT
                        k = len(self.stacks[-1])
                        for i in xrange(k): INDENT
                                if i >= (k-n): INDENT
                                        s.append( self.stacks[-1][i] )
DEDENT DEDENT                         if n > len(s): INDENT
                                s = [Cell(0)]*(n-len(s)) + s
DEDENT DEDENT                 elif n < 0: INDENT
                        # put zeros on the soss (it's in the spec, but what good is it?)
                        for i in xrange(abs(n)): INDENT
                                self.push( Cell(0) )
                # add the new stack we just built
DEDENT DEDENT                 self.stacks.append( s )

DEDENT         def end( self, n ): INDENT
                assert len(self.stacks) > 1
                s = []
                n = n.as_int()
                if n > 0: INDENT
                        k = len(self.stacks[-1])
                        for i in xrange(k): INDENT
                                if i >= (k-n): INDENT
                                        s.append( self.stacks[-1][i] )
DEDENT DEDENT                         if n > len(s): INDENT
                                s = [Cell(0)]*(n-len(s)) + s
DEDENT DEDENT                 elif n < 0: INDENT
                        # rip up the soss
                        for i in xrange(abs(n)): INDENT
                                self.stacks[-2].pop()
DEDENT DEDENT                 for cell in s: INDENT
                        self.soss().append( cell )
DEDENT                 self.stacks.pop()

        # passthrough to toss
DEDENT         def push( self, value ): INDENT
                assert isinstance(value,Cell)
                self.stacks[-1].append( value )
        
DEDENT         def pop( self ): INDENT
                if len(self.stacks[-1]): INDENT
                        v = self.stacks[-1].pop()
DEDENT                 else: INDENT
                        v = Cell(0)
DEDENT                 return v

DEDENT         def __str__( self ): INDENT
                out = ""
                if len(self.stacks) > 0: INDENT
                        out += "TOSS:\n"
                        for i in self.stacks[-1]: INDENT
                                out += "  %s\n" % str(i)
DEDENT DEDENT                 if len(self.stacks) > 1: INDENT
                        out += "SOSS:\n"
                        for i in self.stacks[-2]: INDENT
                                out += "  %s\n" % str(i)
DEDENT DEDENT                 return out
        
DEDENT DEDENT 
