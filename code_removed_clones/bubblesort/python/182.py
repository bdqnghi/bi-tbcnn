def bubble_sort(input_array):
    for i in range(len(input_array) - 1):
        for j in range(len(input_array) - 1):
            if input_array[j] > input_array[j + 1]:
                temp = input_array[j + 1]
                input_array[j + 1] = input_array[j]
                input_array[j] = temp
        print input_array


bubble_sort([21, 4, 1, 3, 9, 20, 25, 6, 21, 14])