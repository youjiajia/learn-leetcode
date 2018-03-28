# -*- coding:utf8 -*-
# 直接选择排序


def chooseSort(array):
    for begin in xrange(len(array)):
        minindex = begin
        for x in xrange(begin+1,len(array)):
            if array[x] < array[minindex]:
                minindex = x
        if minindex != begin:
            array[begin], array[minindex] = array[minindex], array[begin]
    return array

print chooseSort([1,3,5,9,4,2,7,3,1])
