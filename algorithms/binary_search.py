
def binary_search(val, array, start, end):
    if start > end:
        return "not found"
    mid = int((end+start)/2)
    if val == array[mid]:
        return "found"
    if val < array[mid]:
        return binary_search(val, array, start, mid-1)
    else:
        return binary_search(val, array, mid+1, end)


li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(len(li)/2)

print(binary_search(10, li, 0, len(li)-1))
