def merge(A, l, m, r):
	L = [A[i] for i in range(l, m+1)]
	R = [A[i] for i in range(m+1, r+1)]
	i = j = 0
	while (i < len(L) or j < len(R)):
		left = right = float("inf")
		if i < len(L):
			left = L[i]
		if j < len(R):
			right = R[j]
		if left < right:
			A[l+i+j] = left
			i += 1
		else:
			A[l+i+j] = right
			j += 1

def mergesort(A, l, r):
	if l < r:
		m = (l + r)//2
		mergesort(A, l, m)
		mergesort(A, m+1, r)
		merge(A, l, m, r)

A = [38, 27, 43, 3, 7, -5, 0, -1324324, 932432, 99, 22]
print(A)
mergesort(A, 0, len(A) - 1)
print(A)
