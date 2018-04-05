class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        result = []
        result.append(nums[0])
        if len(nums) > 1:
            result.append(max(nums[0], nums[1]))
        for i in xrange(2, len(nums)):
            result.append(max(result[i-1], result[i-2]+nums[i]))
        return result[len(nums)-1]

s = Solution()
print s.rob([0,0])