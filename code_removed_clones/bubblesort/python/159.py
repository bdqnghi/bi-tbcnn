
def bubbleSort(list):
	moreSwaps = True
	while moreSwaps:
		moreSwaps = False
		for element in range(len(list)-1): #checking each element in the list minus 1
			if list[element] > list[element+1]: #if current element is greater than current element plus one
				moreSwaps = True
				temp = list[element] # the next block of code is just switching the elements spots
				list[element] = list[element +1]
				list[element +1] = temp
	return list




import random
arr =random.sample(range(0,10000),100)
list = arr
bubbleSort(list)
print(list)



	





