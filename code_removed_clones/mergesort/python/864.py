import measure

def mergeSort(x):
	l = len(x)
	if l == 1:
		return [x[0]]
	a = mergeSort(x[:l/2])
	b = mergeSort(x[l/2:])		
	return merge(a,b)

def merge(a,b):
	c = []
	(i, k) = (0, 0)
	while(i < len(a) and k < len(b)):
		if(a[i] < b[k]):			
			c.append(a[i])
			i+=1
		else: 
			c.append(b[k])
			k+=1
	c += a[i:]
	c += b[k:]
	return c

def mergeSort2(x):
	l = len(x)
	if l == 1:
		return [x[0]]
	a = mergeSort2(x[:l/2])
	b = mergeSort2(x[l/2:])		
	c = []
	(i, k) = (0, 0)
	while(i < len(a) and k < len(b)):
		if(a[i] < b[k]):			
			c.append(a[i])
			i+=1
		else: 
			c.append(b[k])
			k+=1
	c += a[i:]
	c += b[k:]
	return c

def mergeSort3(a):
	return mergeSortImpl(a, 0, len(a))

def mergeSortImpl(a, r, p):
	l = p - r
	if l <= 1:		
		return [a[r]]
	h1 = mergeSortImpl(a, r, r + l/2)
	h2 = mergeSortImpl(a, r + l/2, p)		
	c = []
	(i, k) = (0, 0)
	while(i < len(h1) and k < len(h2)):
		if(h1[i] < h2[k]):			
			c.append(h1[i])
			i+=1
		else: 
			c.append(h2[k])
			k+=1
	c += h1[i:]
	c += h2[k:]
	return c


def mergeSortBottomUp(a):
	n = len(a)
	width = 1
	b = [0] * n
	while(width < n):
		i = 0		
		while(i < n):
			m = mergeBottomUp(a, i, min(i + width, n), min(i+2*width, n), b)			
			i += 2*width
		(a,b) = (b,a)
		width *= 2
	return a

def mergeBottomUp(a,p,q,r,b):		
	(i, k, j) = (p, q, p)
	while(i < q and k < r):
		if(a[i] < a[k]):						
			b[j] = a[i]
			i+=1
		else: 			
			b[j] = a[k]
			k+=1
		j += 1
	while(i < q):
		b[j] = a[i]
		i += 1
		j += 1
	while(k < r):		
		b[j] = a[k]
		k += 1
		j += 1

measure.time(mergeSort)
measure.time(mergeSort2)
measure.time(mergeSort3)
measure.time(mergeSortBottomUp)
measure.time(sorted)