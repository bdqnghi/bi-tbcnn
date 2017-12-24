def bubbleSort(arr):
	##for every value in the array, swap with the next one if the first < the second until the last two are reached, then recusively call the function without the last value of the list until it is sorted
	##53167248
	for i in range(0, len(arr)-1):
		if arr[i] > arr[i+1]:
			arr[i], arr[i+1] = arr[i+1], arr[i]
		print arr
print bubbleSort([5,3,1,6,7,2,4,8])