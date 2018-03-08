import heapq

class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.big_queue = []
        self.small_queue = []
        heapq.heapify(self.big_queue)
        heapq.heapify(self.small_queue)


    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        if not self.big_queue:
            heapq.heappush(self.big_queue, -num)
            return
        if len(self.big_queue) == len(self.small_queue):
            if num < -self.big_queue[0]:
                heapq.heappush(self.big_queue, -num)
            else:
                heapq.heappush(self.small_queue, num)
        elif len(self.big_queue) > len(self.small_queue):
            if num < -self.big_queue[0]:
                heapq.heappush(self.small_queue, -self.big_queue[0])
                heapq.heapreplace(self.big_queue, -num)
            else:
                heapq.heappush(self.small_queue, num)
        else:
            if num > self.small_queue[0]:
                heapq.heappush(self.big_queue, -self.small_queue[0])
                heapq.heapreplace(self.small_queue, num)
            else:
                heapq.heappush(self.big_queue, -num)


    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.big_queue) == len(self.small_queue):
            return (self.small_queue[0]-self.big_queue[0])/2.0
        elif len(self.big_queue) > len(self.small_queue):
            return -self.big_queue[0]
        else:
            return self.small_queue[0]