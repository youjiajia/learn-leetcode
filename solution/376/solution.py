class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        begin = 0
        up = 1
        down = 2
        state = begin
        max_length = 1
        for i in xrange(1, len(nums)):
            if state == begin:
                if nums[i] > nums[i-1]:
                    state = up
                    max_length += 1
                elif nums[i] < nums[i-1]:
                    state = down
                    max_length += 1
            elif state == up:
                if nums[i] < nums[i-1]:
                    state = down
                    max_length += 1
            elif state == down:
                if nums[i] > nums[i-1]:
                    state = up
                    max_length += 1
        return max_length