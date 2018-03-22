class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = zip(nums, xrange(len(nums)))
        counts = [0] * len(nums)
        self.sortnum(nums, counts)
        return counts

    def sortnum(self, nums, counts):
        if len(nums) < 2:return nums
        mid = len(nums) / 2
        fist_part = nums[:mid]
        second_part = nums[mid:]
        self.sortnum(fist_part, counts)
        self.sortnum(second_part, counts)
        del nums[:]
        i = 0
        j = 0
        while i < len(fist_part) and j < len(second_part):
            if fist_part[i][0] <= second_part[j][0]:
                counts[fist_part[i][1]] += j
                nums.append(fist_part[i])
                i += 1
            else:
                nums.append(second_part[j])
                j += 1
        while i < len(fist_part):
            counts[fist_part[i][1]] += j
            nums.append(fist_part[i])
            i += 1
        while j < len(second_part):
            nums.append(second_part[j])
            j += 1

s = Solution()
print s.countSmaller([5,2,6,1])