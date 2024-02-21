# -*- coding: utf8 -*-
# 构建一个堆数据结构，并实现堆排序，这里使用的是最小堆


class MyHeap(object):
    def __init__(self, l):
        import copy
        self.heap = copy.copy(l)
        for x in range(len(self.heap)//2 - 1, -1, -1):
            self._swapTop(x)

    def _swapTop(self, index):
        size = len(self.heap)
        left = 2*index +1
        right = left + 1
        minindex = index
        if len(self.heap) > left and self.heap[left] < self.heap[minindex]:
            minindex = left
        if len(self.heap) > right and self.heap[right] < self.heap[minindex]:
            minindex = right
        if minindex != index:
            self.heap[index], self.heap[minindex] = self.heap[minindex], self.heap[index]
            self._swapTop(minindex)

    def push(self, x):
        self.heap.append(x)
        i = len(self.heap)
        while True:
            i = i // 2 - 1
            if i < 0:
                i = 0
            self._swapTop(i)
            if i == 0:
                break

    def pop(self):
        x, self.heap[0] = self.heap[0], self.heap[-1]
        self.heap.pop()
        self._swapTop(0)
        return x


L = [2, 5, 3, 5, 1, 5345, 512, 89, 33, 234]
myheap = MyHeap(L)
# for _ in range(len(L)):
#     print(myheap.pop())
# print("="*20)
myheap.push(-1)
# for _ in range(len(L)+1):
#     print(myheap.pop())

