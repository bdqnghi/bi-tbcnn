#!/usr/bin/env python3

myList = [1,10,2,6,7,8,15,3,20,1000,5,9]

# O(n^2)
def bubblesort(sortList):
    swap = True
    # i will count down from the length of the list minus 1 , steps of -1 to 0
    for passNum in range(len(sortList)-1,0,-1):
       swap = False
       for i in range(passNum):
           if sortList[i] > sortList[i+1]:
                temp = sortList[i+1]
                sortList[i+1] = sortList[i]
                sortList[i] = temp
                swap = True
       # if no swaps have been made this pass, break the loop
       if swap == False:
           break
    return sortList

if __name__ == "__main__":
    print(myList)
    sortedList = bubblesort(myList)
    print(sortedList)
