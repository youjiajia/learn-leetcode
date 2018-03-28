# -*- coding:utf8 -*-
# 插入排序


def insertSort(array):
    newarray = []
    for x in array:
        for i in xrange(len(newarray)+1):
            if i == len(newarray) or x < newarray[i]:
                newarray.insert(i, x)
                break
    return newarray

print insertSort([1,3,5,9,4,2,7,3])