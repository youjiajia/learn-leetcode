class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 4:return False
        nums.sort(reverse=True)
        num_s = sum(nums)
        if num_s % 4 != 0:return False
        target = num_s / 4
        if nums[0] < target and nums[0] + nums[-1] > target:return False
        backet = [0] * 4
        return self.generate(0, backet, target, nums)

    def generate(self, i, backet, target,nums):
        if i >= len(nums):
            return backet[0] == target and backet[1] == target and backet[2] == target and backet[3] == target
        for x in xrange(len(backet)):
            backet[x] += nums[i]
            if backet[x] <= target and self.generate(i+1, backet, target, nums):
                return True
            backet[x] -= nums[i]
        return False

s = Solution()
print s.makesquare([1,1,2,2,2])