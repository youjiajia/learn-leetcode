# -*- coding:utf8 -*-
# 有4种面值的邮票很多枚，这4种邮票面值分别1, 4, 12, 21，取5张 求取出这些邮票的最大连续组合值。


def collect(value, m, VALUES):
    if value == 0:
        return True
    elif m <= 0:
        return False
    else:
        for x in VALUES:
            if collect(value-x, m-1, VALUES):
                return True





VALUES = [1,4,12,21]
MAX = 5
value = 1
while True:
    if not collect(value, MAX, VALUES):
        break
    value += 1
print value - 1