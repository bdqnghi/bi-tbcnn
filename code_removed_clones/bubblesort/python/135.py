import random

def doit():
    size = random.randint(0, 214)
    numbers = []
    generated = 0
    i= 0
    limit = size
    while i < limit:
        generated = random.randint(0, size)
        if not generated in numbers:
            numbers.append(generated)
        else:
            limit = limit + 1
        i = i+1
    print "size ", size, " real size ", len(numbers), " limit ", limit
    print "not sorted:", numbers, "\n"
    organized = bubblesort(numbers)
    print "sorted:", organized

def bubblesort(numbers):
    aux = 0
    for i in range(len(numbers), 0, -1):
        if i > 0:
            for j in range(i-1):
                if numbers[j] > numbers[j+1]:
                    aux = numbers[j]
                    numbers[j] = numbers[j+1]
                    numbers[j+1] = aux
    return numbers

doit()
