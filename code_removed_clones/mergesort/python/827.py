def merge(n):
    if len(n) >= 2:
        first = n[:len(n)//2]
        second = n[len(n)//2:]
        merge(first)
        merge(second)
        merge_all(n, first, second)
        
def merge_all(n, a, b):
    i = 0
    j = 0
    for k in range(0, len(n)):        
        if len(a) == i:
            n[k] = b[j]
            j += 1            
            continue
        if len(b) == j:
            n[k] = a[i]
            i +=1            
            continue
        if a[i] < b[j]:
           n[k] = a[i]
           i += 1
        elif b[j] < a[i]:
           n[k] = b[j]
           j += 1
        elif a[i] == b[j]:
           n[k] = a[i]
           i += 1


