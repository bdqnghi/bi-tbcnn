#Quicksort algorithm (Chapter 7)

#quicksort worst case: O(n^2) - already sorted array
#quicksort avg case: O(n lg n) - usually faster than heapsort

#balanced_partitioning ~= mergesort
#not_balanced_partitioning ~=insertion sort

#tip: randomize quicksort to obtain performance on avg case for all possible inputs

#the right choice algorithm: http://stackoverflow.com/questions/1933759/when-is-each-sorting-algorithm-used

A = [2,8,7,1,3,5,6,4]

def quicksort(A,p,r):
	
	print('[quicksort] p='+str(p)+' r='+str(r))
	
	if p < r:
		q = partition(A,p,r)
		
		print('[quicksort] q='+str(q) +' A='+str(A))
		
		quicksort(A,p,q-1)
		quicksort(A,q+1,r)
		
def partition(A,p,r):
	i = p
	for j in range(p+1,r+1):
		if A[j] < A[p]:
			i +=1
			A[i],A[j] = A[j],A[i]
	A[p] , A[i] = A[i],A[p]
	
	return i

def main():
	print('[quicksort] input:' +str(A))
	quicksort(A,0,len(A)-1)
	print('[quicksort] output:' +str(A))
	
if __name__ == "__main__": main()
	