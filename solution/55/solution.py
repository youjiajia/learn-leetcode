class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max = nums[0]
        index = 0
        while index <= max:
            if max >= len(nums)-1:
                return True
            number = nums[index] + index
            if number > max:
                max = number
            index += 1
        return False