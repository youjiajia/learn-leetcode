# -*- coding:utf8 -*-
# 基数排序 分MSD和LSD
import math

def LSDSort(array, d):
    i = 0
    while i < d:
        s = [[] for _ in range(10)]
        for x in array:
            s[x//(10**i)%10].append(x)
        array = [y for x in s for y in x]
        i += 1
    return array

def generate(array, i, d):
    if i < 0:
        return array
    s = [[] for _ in range(10)]
    for x in array:
        s[x//(10**i)%10].append(x)
    s = [generate(x, i-1, d) for x in s]
    array = [y for x in s for y in x]
    return array

def MSDSort(array, d):
    return generate(array, d, d)


array = [1,34,5,9298,4,222222,7,3,133]
d = int(math.ceil(math.log(max(array), 10)))
print(LSDSort(array, d))
print(MSDSort(array, d))