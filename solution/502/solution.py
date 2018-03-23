import heapq

class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        max_queue = []
        newlist = zip(Capital, Profits)
        newlist.sort()
        i = 0
        while k > 0 and i < len(Capital):
            if W >= newlist[i][0]:
                if newlist[i][1] > 0:heapq.heappush(max_queue, -newlist[i][1])
            elif len(max_queue) < 1:break
            else:
                W -= heapq.heappop(max_queue)
                k -= 1
                i -= 1
            i += 1
        while k > 0 and len(max_queue) > 0:
            W -= heapq.heappop(max_queue)
            k -= 1
        return W