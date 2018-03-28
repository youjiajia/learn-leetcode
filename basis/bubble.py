# -*- coding:utf8 -*-
# 冒泡排序


def bubbleSort(array):
    for i in xrange(len(array)-1, -1, -1):
        for x in xrange(i):
            if array[x] > array[x+1]:
                array[x], array[x+1] = array[x+1], array[x]
    return array

print bubbleSort([1,3,5,9,4,2,7,3])
