# -*- coding:utf8 -*-
# 归并排序

def mergeSort(array):
    if len(array) < 2:
        return array
    if len(array) == 2:
        return array[0]<=array[1] and [array[0], array[1]] or [array[1], array[0]]
    left = mergeSort(array[:len(array)/2])
    right = mergeSort(array[len(array)/2:])
    i = 0
    j = 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    while i < len(left):
        result.append(left[i])
        i += 1
    while j < len(right):
        result.append(right[j])
        j += 1
    return result


print mergeSort([1,3,5,9,4,2,7,3])
