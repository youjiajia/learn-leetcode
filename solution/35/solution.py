class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        index = -1
        begin = 0
        end = len(nums) -1
        while index == -1:
            mid = (begin+end)/2
            if nums[mid] == target:index = mid
            if nums[mid] > target:
                if mid == 0 or nums[mid - 1] < target:
                    index = mid
                end = mid -1
            if nums[mid] < target:
                if mid == len(nums) -1 or nums[mid + 1] > target:
                    index = mid + 1
                begin = mid + 1
        return index