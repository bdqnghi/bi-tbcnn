import math
import random

def createList(size):
	ret = []
	for x in range(0, size):
		ret.insert(0, math.ceil(random.random() * 100))

	return ret

def mergeSort(unsortedList):
	result = split(unsortedList)
	print result
	
	
def split(arr):
	length = arr.__len__()
	if (length == 1):
		return arr
	else:
		a = split(arr[0:int(math.floor(length / 2))])
		b = split(arr[int(math.floor(length / 2)):length])

		return merge(a,b)
	

def merge(arr1, arr2):
	ret = []
	pos1 = 0
	pos2 = 0
	while (arr1.__len__() > pos1 and arr2.__len__() > pos2):
		if (arr1[pos1] < arr2[pos2]):
			ret.append(arr1[pos1])
			pos1 += 1
		else:
			ret.append(arr2[pos2])
			pos2 +=1
	
	ret = ret + arr1[pos1:arr1.__len__()] + arr2[pos2:arr2.__len__()]
	return ret

toBeSorted = createList(2000)
print toBeSorted
result = mergeSort(toBeSorted)
print result
