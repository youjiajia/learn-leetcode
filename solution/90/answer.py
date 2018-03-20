class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        nums.sort()
        for num in nums:
            result += [i+[num] for i in result if i+[num] not in result]
        return result


s = Solution()
print s.subsetsWithDup([1,2,2])