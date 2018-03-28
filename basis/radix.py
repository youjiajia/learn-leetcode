# -*- coding:utf8 -*-
# 基数排序 分MSD和LSD


def LSDSort(array, d):
    i = 0
    while i < d:
        s = [[] for _ in xrange(10)]
        for x in array:
            s[x/(10**i)%10].append(x)
        array = [y for x in s for y in x]
        i += 1
    return array


print LSDSort([1,3,5,9,4,2,7,3,1], 1)