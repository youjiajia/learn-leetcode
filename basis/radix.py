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

def generate(array, i, d):
    if i < 0:
        return array
    s = [[] for _ in xrange(10)]
    for x in array:
        s[x/(10**i)%10].append(x)
    s = [generate(x, i-1, d) for x in s]
    array = [y for x in s for y in x]
    return array

def MSDSort(array, d):
    return generate(array, d, d)

print LSDSort([1,34,5,92,4,2,7,3,133], 3)
print MSDSort([1,34,5,92,4,2,7,3,133], 3)