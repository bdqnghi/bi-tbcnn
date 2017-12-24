lst = [54, 26, 93, 17, 77, 31, 44, 55, 20]

def bubblesort(lst):
    # Starting backwards
    for passnum in range(len(lst)-1, 0, -1):
        print("------------ ", passnum)
        for i in range(passnum):
            print("lst[i]: %s | lst[i+1]: %s" % (lst[i], lst[i+1]))
            if lst[i] > lst[i+1]:
                temp = lst[i]
                lst[i] = lst[i+1]
                lst[i+1] = temp
            print(lst)

if __name__ == "__main__":
    print("start: ", lst)
    bubblesort(lst)
    print("end: ", lst)
