def bubblesort(a):
	"""
	use bubble sort to sort list a
	input: list a
	output: list a in non-descending order
	"""
	for i in range(0, len(a) - 1):
		for j in range(0, len(a) - 1 - i):
			if a[j + 1] < a[j]:
				# swap the two numbers
				a[j + 1], a[j] = a[j], a[j + 1]

	return a


# test 
if __name__ == '__main__':
	a = [-34, 83, 9, 1, 44, 999, 23, 11, -8]
	print(bubblesort(a))
