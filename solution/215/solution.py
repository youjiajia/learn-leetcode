import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heapq.heapify(nums)
        if len(nums) >= k:
            return heapq.nlargest(k, nums)[k-1]
        return None