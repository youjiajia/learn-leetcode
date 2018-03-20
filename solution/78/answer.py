class Solution(object):

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        allnum = 1 << len(nums)
        result = []
        for i in xrange(allnum):
            item = []
            for x in xrange(len(nums)):
                if (1 << x) & i:
                    item.append(nums[x])
            result.append(item)
        return result


s = Solution()
print s.subsets([1,2,3])