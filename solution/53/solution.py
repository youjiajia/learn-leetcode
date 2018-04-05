class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        datas = [nums[0]]
        result = nums[0]
        for i in xrange(1, len(nums)):
            datas[i] = max(nums[i], datas[i-1]+nums[i])
            if result < datas[i]:
                result = datas[i]
        return result