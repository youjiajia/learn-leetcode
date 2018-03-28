# -*- coding:utf8 -*-
# 快速排序的py实现

def quickSort(array):
    if len(array) < 2:
        return array
    else:
        first = array[0]
        left = quickSort([x for x in array[1:] if x < first])
        right = quickSort([x for x in array[1:] if x >= first])
        return left + [first] + right


print quickSort([1,3,5,9,4,2,7,3])
