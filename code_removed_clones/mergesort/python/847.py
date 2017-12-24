# n = 123
# f = 456.789
# s1 = 'Hello, world'
# s2 = 'Hello, \'Adam\''
# s3 = r'Hello, "Bart"'
# s4 = r'''Hello,
# Lisa!'''
# print (n,f,s1,s2,s3,s4)

# for x in range(101):
# 	pass
# print(x)

   
# def mergesort (a,tmpa,left,right):
# 	if left>=right:
# 		print (a[right])
# 		return a[right]
# 	if left<right:
# 		center = (left+right)//2
# 		mergesort(a,tmpa,left,center)
# 		mergesort(a,tmpa,center+1,right)
# 		return merge(a,tmpa,left,center+1,right)
# def merge(a,tmpa,leftPos,rightPos,rightEnd):
# 	leftEnd = rightPos - 1
# 	tmpPos = leftPos
# 	numElement = rightEnd - leftPos +1
# 	while leftPos<=leftEnd and rightPos<=rightEnd: # and insted of &&
# 		if a[leftPos]<=a[rightPos]:
# 			tmpa[tmpPos] = a[leftPos]
# 			tmpPos+=tmpPos
# 			leftPos+=leftPos
# 		else:
# 		    tmpa[tmpPos] = a[rightPos]
# 		    tmpPos+=tmpPos
# 		    rightPos+=rightPos
# 	while leftPos<=leftEnd:
# 	   	  tmpa[tmpPos] = a[leftPos]
# 	   	  tmpPos+=tmpPos
# 	   	  leftPos+=leftPos
# 	while leftPos<=rightEnd:
# 		  tmpa[tmpPos] = a[rightPos]
# 		  tmpPos+=tmpPos
# 		  rightPos+=rightPos
# 	i=0
# 	while i<numElement:
# 	   a[rightEnd] = tmpa[rightEnd]
# 	   i+=1;
# 	   rightEnd+=rightEnd
# 	return a;
# a=[3,2,1,0]
# tmpa=a
# mergesort(a,tmpa,0,len(a)-1)


from collections import deque

def merge_sort(lst):
    if len(lst) <= 1:
        return lst

    def merge(left, right):
        merged,left,right = deque(),deque(left),deque(right)
        while left and right:
            merged.append(left.popleft() if left[0] <= right[0] else right.popleft())  # deque popleft is also O(1)
        merged.extend(right if right else left)
        return list(merged)

    middle = int(len(lst) // 2)
    left = merge_sort(lst[:middle])
    right = merge_sort(lst[middle:])
    return merge(left, right)

lst=[3,2,4,1,0]
lst=merge_sort(lst)
print (lst)