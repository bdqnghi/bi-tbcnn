# Sort the characters in an array.

# sort characters in array
# assume that lowercase > uppercase (based on standard python character sorting)

def sort(char_array):
    # base case
    if len(char_array) <= 1:
        return char_array

    # pick a middle area and sort on either side
    mid_index = len(char_array) / 2

    left = char_array[0:mid_index]
    right = char_array[mid_index:]

    # sort each side
    sorted_left = sort(left)
    sorted_right = sort(right)

    # merge 'em together
    return merge(sorted_left, sorted_right)


def merge(array_a, array_b):
    # merge two sorted arrays (small => large)
    built = []

    # pull off lowest item off a and b until they're empty
    while len(array_a) != 0 and len(array_b) != 0:
        min_a = array_a[0]
        min_b = array_b[0]

        if min_a < min_b:
            built.append(array_a.pop(0))
        else:
            built.append(array_b.pop(0))

    # now one of them is empty
    built.extend(array_a)
    built.extend(array_b)

    return built


print merge([1,4,5],[2,3,8,9,10])

print sort([3,1,5,4,2,8,6,3,7,9])
print sort([])
print sort([5])
print sort([3,2])
print sort([5,4,9])

print sort(list("syzygy"))
