#!/usr/bin/which python

array = [1,3,5,83,1342,6546,432,654,321,111,34121,9880]

def bubble_sort(array):
	swapped, j = True, 1
	length = len(array)
	while(swapped):
		swapped = False
		for i in range(0, length-j):
			if ( array[i] >= array[i+1] ):
				temp = array[i]
				array[i] = array[i+1]
				array[i+1] = temp
				swapped = True
		j += 1

print "Numbers to be sorted are:\n%r" % array
bubble_sort(array)
print "Sort results are:\n%r" % array
