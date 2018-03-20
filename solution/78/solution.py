import copy
class Solution(object):
    def generate(self, n, nums, item, result):
        if n >= len(nums):return
        item.append(nums[n])
        result.append(copy.copy(item))
        self.generate(n+1, nums, item, result)
        item.pop()
        self.generate(n+1, nums, item, result)

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        item = []
        result = []
        result.append(item)
        self.generate(0, nums, item, result)
        return result

s = Solution()
print s.subsets([1,2,3])