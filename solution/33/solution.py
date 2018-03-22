class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        begin = 0
        end = len(nums) - 1
        while begin <= end:
            mid = (begin + end) / 2
            if nums[mid] == target: return mid
            if nums[mid] > target:
                if nums[begin] < nums[mid]:
                    if nums[begin] > target:
                        begin = mid + 1
                    elif nums[begin] < target:
                        end = mid -1
                    else: return begin
                elif nums[begin] > nums[mid]:
                    end = mid - 1
                else:
                    begin = mid + 1
            elif nums[mid] < target:
                if nums[begin] < nums[mid]:
                    begin = mid + 1
                elif nums[begin] > nums[mid]:
                    if nums[begin] > target:
                        begin = mid + 1
                    elif nums[begin] < target:
                        end = mid - 1
                    else: return begin
                else:
                    begin = mid + 1
        return -1