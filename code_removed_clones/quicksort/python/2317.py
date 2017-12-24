def swap(a, i, j):
	a[i], a[j] = a[j], a[i]

def partition(a, start, end):
	pivot = a[end]
	partition_index = start
	for i in range(start, end):
		if a[i] <= pivot:
			swap(a, i, partition_index)
			partition_index += 1
	swap(a, partition_index, end)
	return partition_index

def quickSort(a, start, end):
	if start < end:
		partition_index = partition(a, start, end)
		quickSort(a, start, partition_index-1)
		quickSort(a, partition_index+1, end)
	print(a)

if __name__ == '__main__':
	a = [7,2,1,6,8,5,3,4]
	# print(partition(a, 0, len(a)-1))
	quickSort(a, 0, len(a)-1)



