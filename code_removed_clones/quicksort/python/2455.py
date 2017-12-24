import measure


def quickSort(a):
	n = len(a)
	if n == 0: return []
	pivot = a[n-1]
	(l, r) = partition(a[:-1], pivot)
	return quickSort(l) + [pivot] + quickSort(r)

def partition(a, pivot):
	l = [x for x in a if x < pivot]
	r = [x for x in a if x >= pivot]
	return (l,r)

def quickSort2(a):
	return quickSort2Impl(a,0,len(a))

def quickSort2Impl(a, p, r):
	n = r - p
	if n == 0: return []
	pivot = a[r-1]
	(x, y) = partition(a[p:r-1], pivot)
	return quickSort2Impl(x,0,len(x)) + [pivot] + quickSort2Impl(y,0,len(y))

def quickSort3(a):
	return quickSort3Impl(a,0,len(a))

def quickSort3Impl(a, p, r):
	n = r - p
	if n == 0: return []
	mid = partition3(a, p, r)	
	quickSort3Impl(a,p,mid)
	quickSort3Impl(a,mid+1,r)
	return a

def partition3(a,p,r):
	n = r - p
	if(n <= 1): return p
	pivot = a[r-1]
	i = p
	k = r - 1
	while(i < k):
		if(a[i] < pivot):
			i += 1
		else:
			k -= 1
			a[i], a[k] = a[k], a[i]			
	a[i], a[r-1] = a[r-1], a[i]
	return i

def quickSort4(a):
	return quickSort3Impl(a,0,len(a))

def quickSort4Impl(a, p, r):
	n = r - p
	if n == 0: return []
	while(n > 1):
		mid = partition3(a, p, r)	
		quickSort4Impl(a,p,mid)
		p = mid + 1
		n = r - p		
	return a

measure.time(quickSort)
measure.time(quickSort2)
measure.time(quickSort3)
measure.time(quickSort4)


