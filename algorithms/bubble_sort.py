from random import randint

array = [randint(0, 20) for i in range(0, 20)]

print(array)


def bubble_sort(array):
    for i in range(len(array)-1):
        swapped = False
        for j in range(len(array)-i-1):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp


print(len(array))
bubble_sort(array)
print(array)
print(len(array))
