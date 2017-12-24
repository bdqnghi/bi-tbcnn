def bubble(bubbleList):
    listLength = len(bubbleList)
    while listLength > 0:
        for i in range(listLength - 1):
            if bubbleList[i] > bubbleList[i+1]:
                bubbleList[i] = bubbleList[i] + bubbleList[i+1]
                bubbleList[i+1] = bubbleList[i] - bubbleList[i+1]
                bubbleList[i] = bubbleList[i] - bubbleList[i+1]
        listLength -= 1
    print(bubbleList)
if __name__ == '__main__':
    bubbleList = [3, 4, 1, 2, 5, 8, 0]
    print(bubbleList)
    bubble(bubbleList)
 