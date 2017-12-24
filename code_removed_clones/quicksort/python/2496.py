# coding=utf-8

def partition(targetlist, low, high):
	x = targetlist[low]
	while (low<high):
		# print low, high
		while ((low<high) & (targetlist[high]<=x)):
			high -= 1
		targetlist[low] = targetlist[high]
		while ((low<high) & (targetlist[low]>=x)):
			low += 1
		targetlist[high] = targetlist[low]
	targetlist[low] = x
	return low, targetlist

# search the kth larger number
def search(targetlist, i, j, k):
	if (i<=j):
		q, _ = partition(targetlist, i, j)
		print q
		if (q-i+1==k):
			print "the", q+1, "th max number is: ", targetlist[q]
			return
		elif (q-i+1<k):
			search(targetlist, q+1,j,k-(q-i+1))
		else:
			search(targetlist, i, q-1, k)
			
	print targetlist

# quick sort code
def quicksort(targetlist, low, high):
	if low<high:
		q,_=partition(targetlist,low,high)
		quicksort(targetlist,low,q)
		quicksort(targetlist,q+1,high)


# main
l1 = [4,2,6,10,1,8,23,9,6,4,0,12]
search(l1, 0, len(l1)-1, 4)

quicksort(l1,0,len(l1)-1)
print l1
