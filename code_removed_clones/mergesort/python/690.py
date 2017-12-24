def mergesort(a):
	"""
	call mergesort recursively to sort list a
	input: list a
	output: list a in non-descending order 
	"""
	if len(a) > 1:
		mid = int(len(a) / 2)
		a_left = a[:mid]
		a_right = a[mid:]
		left = mergesort(a_left)
		right = mergesort(a_right)
		result = merge(left, right)
		return result
	else:
		return a

def merge(a, b):
	"""
	merge two non-descending lists into one non-descending list
	input: two non-descending lists
	output: one non-descending list
	"""
	i = 0
	j = 0
	result = []
	while i < len(a) and j < len(b):
		if a[i] <= b[j]:
			result.append(a[i])
			i += 1
		else:
			result.append(b[j])
			j += 1

	# one list has come to end
	if i == len(a):# it is list a that comes to an end
		result = result + b[j:]# list in python could be added directly
	else:
		result = result + a[i:]
	return result
