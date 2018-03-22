class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 1:return [-1, -1]
        left = self.searchLeft(nums, target)
        return [left, self.searchRight(left, nums, target)]

    def searchLeft(self, nums, target):
        begin = 0
        end = len(nums) - 1
        while begin + 1 < end:
            mid = (begin + end) / 2
            if nums[mid] >= target:
                end = mid
            else:
                begin = mid
        if nums[begin] == target:return begin
        elif nums[end] == target: return end
        return -1

    def searchRight(self, left, nums, target):
        if left == -1:
            return -1
        if left == len(nums) - 1:
            return left
        begin = left
        end = len(nums) - 1
        while begin+1 < end:
            mid = (begin + end) / 2
            if nums[mid] > target:
                end = mid
            else:
                begin = mid
        if nums[end] == target:return end
        elif nums[begin] == target: return begin
        return -1


