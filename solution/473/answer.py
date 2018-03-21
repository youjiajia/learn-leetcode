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
        oresult = []
        sresult = []
        allnum = 1 << len(nums)
        for i in xrange(allnum):
            isum = 0
            for x in xrange(len(nums)):
                if 1<<x & i:
                    if nums[x] > target:return False
                    isum += nums[x]
                    if isum > target:break
            if isum == target:oresult.append(i)
        for x in oresult:
            for y in oresult:
                if x & y:continue
                sresult.append(x | y)
        for x in sresult:
            for y in sresult:
                if x & y:continue
                return True
        return False

s = Solution()
print s.makesquare([4,8,12,16,20,24,28,32,36,40,44,48,52,56,60])