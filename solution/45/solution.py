class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        max = nums[0]
        standby = 0
        index = 0
        step = 1
        while index <= max:
            if max >= len(nums)-1:
                return step
            if standby >= len(nums)-1:
                return step+1
            number = nums[index] + index
            if number > standby:
                standby = number
            if index == max:
                max = standby
                step += 1
            index += 1
        return -1