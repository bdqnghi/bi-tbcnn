import random as r
a = []
for i in range(10):
	a.append(int(r.random() * 100))
aux = [0] * len(a) 


def merge(a, aux, low, mid, high):
	i,j = low, mid + 1
	for k in range(low, high + 1):
		aux[k] = a[k]

	for k in range(low, high + 1):
		if i > mid:
			a[k] = aux[j]
			j += 1
		elif j > high:
			a[k] = aux[i]
			i += 1
		elif aux[i] < aux[j]:
			a[k] = aux[i]
			i += 1
		else:
			a[k] = aux[j]
			j += 1

def merge_sort(a, aux, low, high):
	if low < high:
		mid = int((low + high) / 2)
		merge_sort(a, aux, low, mid)
		merge_sort(a, aux, mid + 1, high)
		merge(a, aux, low, mid, high)


merge_sort(a, aux, 0, len(a) - 1)
print(a)