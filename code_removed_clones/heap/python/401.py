import math

class keyval(): INDENT
    def __init__(self,key,value): INDENT
        self.key = key
        self.value = value
DEDENT DEDENT '''
iParent = floor((i-1)/2)
iLeft = 2i+1
iRight= 2i+2
'''
class heap(): INDENT
    def __init__(self): INDENT
        self.array = [0,0,0,0,0,0,0,0,0,0] #10
        
DEDENT     def insert(self, value): INDENT
        for i in range(0,10): INDENT
            if int(math.floor((i-1)/2)) < 0: INDENT
                iparent = 0
DEDENT             else: INDENT
                iparent = int(math.floor((i-1)/2))
DEDENT             ileft = (2*i)+1
            iright = (2*i)+2
            print iparent,ileft,iright
            if self.array[iparent] == 0: INDENT
                print iparent
                self.array[iparent] = value
                break
DEDENT             elif self.array[ileft] == 0: INDENT
                print ileft
                self.array[ileft] = value
                break
DEDENT             elif self.array[iright] == 0: INDENT
                print iright
                self.array[iright] = value
                break
DEDENT             else: INDENT
                print 'looping again!'
DEDENT DEDENT         print self.array
    
DEDENT     def printh(self): INDENT
        print self.array
        
DEDENT DEDENT def main(): INDENT
    tree = heap()
    tree.insert(12)
    tree.insert(5)
    tree.insert(22)
    tree.insert(8)
    tree.insert(1)
    tree.insert(3)
    tree.printh()
    
DEDENT if __name__ == '__main__': INDENT
    main()
DEDENT 
