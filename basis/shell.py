# -*- coding:utf8 -*-
# 希尔排序

def shellSort(array):
    step = len(array)
    while step != 1:
        step /= 2
        for k in xrange(step, len(array)):
            for i in xrange(k-step, -1, -step):
                if array[i] > array[i+step]:
                    array[i], array[i+step] = array[i+step], array[i]
    return array

print shellSort([1,3,5,9,4,2,7,3,1])
