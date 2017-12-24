def quickSort(lst, lo, hi):
  ls, hs = lo, hi
  middle = (ls + hs) / 2

  while ls < hs:
    print "ls=%d, hs=%d, middle=%d" % (ls, hs, middle)
    if lst[ls] <= lst[middle]:
      ls += 1
    elif lst[ls] > lst[middle]:
      orig_ls, orig_middle = lst[ls], lst[middle]
      lst[ls], lst[middle] = orig_middle, orig_ls
    elif lst[hs].key >= lst[middle].key:
      hs -= 1
    elif lst[hs].key < lst[middle].key:
      orig_hs, orig_middle = lst[hs], lst[middle]
      lst[hs], lst[middle] = orig_middle, orig_hs

    quickSort(lst, ls, hs)

  return lst