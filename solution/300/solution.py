class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:return len(nums)
        result = 1
        lenlist = [1] * len(nums)
        for i in xrange(1, len(nums)):
            for j in xrange(i):
                if nums[i] > nums[j] and lenlist[i] < lenlist[j] + 1:
                    lenlist[i] = lenlist[j] + 1
                    if result < lenlist[i]:
                        result = lenlist[i]
        return result