import copy
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        item = []
        result = [[]]
        self.generate(0, nums, item, result)
        return result

    def generate(self, i, nums, item, result):
        if i >= len(nums):return
        item.append(nums[i])
        if item not in result:result.append(copy.copy(item))
        self.generate(i+1, nums, item, result)
        item.pop()
        self.generate(i+1, nums, item, result)


s = Solution()
print s.subsetsWithDup([1,2,2])