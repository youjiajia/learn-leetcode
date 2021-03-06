import copy
class Solution(object):
    def generate(self, n, nums, item, result):
        if n >= len(nums):return
        result.append(item+[nums[n]])
        item += [nums[n]]
        self.generate(n+1, nums, item, result)
        item.pop()
        self.generate(n+1, nums, item, result)

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        self.generate(0, nums, [], result)
        return result

s = Solution()
print s.subsets([1,2,3])