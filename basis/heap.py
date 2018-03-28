# -*- coding: utf8 -*-
# 构建一个堆数据结构，并实现堆排序，这里使用的是最小堆


class MyHeap(object):
    def __init__(self, l):
        self.heap = l
        for x in xrange(len(self.heap)/2, -1, -1):
            self._swapTop(x)

    def _swapTop(self, index):
        size = len(self.heap)
        left = 2*index
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
        self._swapTop(len(self.heap)/2)

    def pop(self):
        x, self.heap[0] = self.heap[0], self.heap[-1]
        self.heap.pop()
        self._swapTop(0)
        return x

myheap = MyHeap([6,8,2,4,5])
myheap.push(7)
for _ in xrange(6):
    print myheap.pop()

