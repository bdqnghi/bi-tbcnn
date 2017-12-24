#Function for merge sorting

def mergesort(alist):
  if len(alist) > 1:            #if list is one element or less just return it
    mid == len(alist)//2        #use floor division to find the mid
    lefthalf = alist[:mid]      #slice the list up to mid
    righthalf = alist[mid:]     #slice the list from mid up
    
    mergesort(lefthalf)         #do this recursively
    mergesort(righthalf)
    
    i = 0
    j = 0
    k = 0
    
    while len(lefthalf) > i and len(righthalf) > j:
      if lefthalf[i] < righthalf[j]:          #if the first element in the right half is greather than the corresponding in left
        alist[k] = lefthalf[i]                #put that element as the first element in alist
        i += 1                                #increase i and repeat
      else:
        alist[k] = righthalf[j]               #as above but other case
        j += 1
      k += 1
      
      while i < len(lefthalf):              #merge lefthalf into list
        alist[k] = lefthalf[i]
        i += 1
        k += 1
        
      while j < len(righthalf):             #then merge right half into list
        alist[k] = righthalf[j]
        j += 1
        k += 1
  print(alist)                              #print the list
  
