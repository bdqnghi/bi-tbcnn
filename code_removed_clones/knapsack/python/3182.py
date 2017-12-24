import random
import timeit

def knaprecur(j,i):
    if j==0:
        o[0][i]=0
        return 0
    if i<0:
        return 0
    else:
        if o[j][i-1]==-1:
            o[j][i-1]=knaprecur(j,i-1)
        if j-w[i]>=0:
            if o[j-w[i]][i-1]==-1:
                o[j-w[i]][i-1]=knaprecur(j-w[i],i-1)
            o[j][i]=max(o[j][i-1],o[j-w[i]][i-1]+v[i])
        else:
            o[j][i]=o[j][i-1]
        return o[j][i]

def knap1(wei):
    global o
    o = [[-1 for i in range(n)] for j in range(wei+1)]
    return knaprecur(wei,n-1)

def knap2(wei):
    o = [[-1 for i in range(n)] for j in range(wei+1)]
    for j in range(wei+1):
        for i in range(n):
            if j==0:
                o[0][i]=0
            elif i==0:
                if j>=w[0]:
                    o[j][0]=v[i]
                else:
                    o[j][0]=0
            else:
                o[j][i]=max(o[j][i-1],o[j-w[i]][i-1]+v[i])
    return o[wei][n-1]

def main():
    global w,v,n
    n=100
    v=[random.randint(0,10000) for i in range(n)]
    w=[random.randint(0,100) for i in range(n)]
    print timeit.timeit("knap1(wei)",setup="from __main__ import knap1; wei=100",number=1)
    print timeit.timeit("knap2(wei)",setup="from __main__ import knap2; wei=100",number=1)

main()