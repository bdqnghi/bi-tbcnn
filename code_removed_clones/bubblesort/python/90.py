def sort(lst):
  lst = list(lst);
  swapped = True;
  while swapped:
    swapped = False;
    for i in range(len(lst)-1):
      if lst[i] > lst[i+1]:
        lst[i], lst[i+1] = lst[i+1], lst[i];
        swapped = True;
  return lst

if __name__ == '__main__':
  biglist = [];
  x = 20000;
  for i in range(0, x):
    biglist.append(x-i);

  unsortedList = ["brandon", "brandonb", "bond", " ", "br", "bond1", "ba", "bond", "1bran"];
  sortedList = BubbleSort(biglist);
  for i in sortedList:
    print i;