#!/usr/bin/env python
# -*- coding: utf-8 -*-

def sort(array):
	bubblesort(array)
	
def bubblesort(array):
	for i in range(len(array) - 1):
		for j in range(1, len(array) - i):
			if array[j - 1] > array[j]:
				array[j - 1], array[j] = array[j], array[j - 1]

if __name__ == '__main__':
	array = [2, 0, 7, 3, 4, 6, 5, 8, 1, 9]
	print 'Source:', array

	sort(array)
	print 'Result:', array