import math

#sample imput data
D = []
#our heap, stored as an array
H = [None]
#next empty space in the heap
N = 0

def insert(x): INDENT
   global N 
   H[N] = x
   bubble_up(N)
   N = N + 1
   H.append(None)
   print_heap()

DEDENT def getMin(): INDENT
   global N 
   print N
   x = H[0]
   N = N - 1
   H[0] = H[N]
   H[N] = None
   bubble_down(1)
   return x
   
DEDENT def bubble_down(n): INDENT
   k = (n*2)-1
   #base case
   print k, N
   if k >= N: INDENT
      return
DEDENT    x = None
   #for the 0 starting index
   n = n - 1
   if k+1>=N: INDENT
      if H[n] > H[k]: INDENT
         x = k
         swap(n, k)
DEDENT       print 'bsd'
DEDENT    else: INDENT
      print 'asd'
      if H[n] > max(H[k], H[k+1]): INDENT
         if H[k] > H[k+1]: INDENT
            x = k+1
            swap(n, k+1)
            print 'bb'
DEDENT          else: INDENT
            x = k
            swap(n,k)
            print 'cc'
   #adding one makes searching for elements easier in the next iteration
   #if we don't add a 1, lets say n = 2 (with 0 base), then it's child elements
   #in the array are not n*2 and n*2+1... instead they are actually n*3 and n*3+1
   #bubble_down(x+1)
         
DEDENT DEDENT DEDENT DEDENT def swap(n, k): INDENT
   t = H[k]
   H[k] = H[n]
   H[n] = t

#bubble  up or 'heapify'
DEDENT def bubble_up(n): INDENT
   #no need to get floor, since int values automatically get floor
   #subtract one bc array starts at 0 index 
   v =(n-1)/2
   #base case
   if v < 0: INDENT
      return 
DEDENT    print v
   if H[n] < H[v]: INDENT
      #swap h[v] with h[n]
      t = H[v]
      H[v] = H[n]
      H[n] = t
      bubble_up(v)
      


#takes O(N) time 
DEDENT DEDENT def print_heap(): INDENT
   i = 0 
   p = 1
   f = 0
   size = len(H)
   #calculate closest 2 power of heap's size
   tmp = int(math.log(size)/math.log(2))+1
   #we will go at each level (p) and print only the
   #elements at that level.  
   while p <= tmp: INDENT
        s0 = 2**(tmp-f)
        print '-' * s0,
        a = 2**(tmp-f+1)-3
        while i < 2**p-1 and i < size: INDENT
           print H[i],'-'*a,
           i = i + 1
DEDENT         print ''
        p = p + 1
        f = f + 1
        
DEDENT DEDENT 
