def kp(arr,i,j):
    if i <j:
        base=kpgc(arr,i,j)
        kp(arr,i,base)
        kp(arr,base+1,j)
def kpgc(arr,i,j):
    base = arr[i]
    while i<j:
        while i<j and arr[j]>=base:
            j-=1
        while i<j and arr[j]<base:
            arr[i]=arr[j]
            i+=1
            arr[j]=arr[i]
    arr[i]=base
    return i

"""kpgc()是快排过程函数：其作用是返回的i指针的位置 也就是原始列表第一个数据经过kpgc（）一次之后在新列表中的位置 
然后将i的值赋值给base，kpgc（）每次都会对arr［］排一次序"""
