#!/usr/bin/python
#_*_coding:utf-8_*_


def rand(x):
	import random
	if x < 3:
		x = 5
	if x > 1000:
		print "big data"
		return []
	l = range(1, x)
	li = []
	while l:
		r = random.randint(0,len(l)-1)
		li.append(l.pop(r))
	return li


def quicksort(l,low, hight):
	key = l[low]
	while low < hight:
		while key <= l[hight] and low < hight:
			hight -= 1
		l[low], l[hight] = l[hight], l[low]

		while key>= l[low] and low<hight:
			low += 1
		l[low], l[hight] = l[hight], l[low]

	l[hight] = key
	return hight

	


def m_sort(l,low,hight):

	if low >=hight:
		return 
	
	index = quicksort(l,low,hight)
	m_sort(l,low,index)
	m_sort(l,index+1,hight)

def main():
	l = rand(150)
	m_sort(l,0,len(l)-1)
	print l

if __name__ == '__main__':
	main()
