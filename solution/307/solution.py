def build_segment_tree(value, nums, pos, left, right):
    if left == right:
        value[pos] = nums[left]
        return
    mid = (left + right) / 2
    build_segment_tree(value, nums, pos*2+1, left, mid)
    build_segment_tree(value, nums, pos*2+2, mid+1, right)
    value[pos] = value[pos*2+1] + value[pos*2+2]

def sum_segment_tree(value, pos, left, right, qleft, qright):
    if qleft > right or qright < left:
        return 0
    if qleft <= left and qright >= right:
        return value[pos]
    mid = (left + right) / 2
    return sum_segment_tree(value, pos*2+1, left, mid, qleft, qright) + sum_segment_tree(value, pos*2+2, mid+1, right, qleft, qright)

def update_segment_tree(value, pos, left, right, index, new_value):
    if left == right == index:
        value[pos] = new_value
        return
    mid = (left + right) / 2
    if index <= mid:
        update_segment_tree(value, pos*2+1, left, mid, index, new_value)
    else:
        update_segment_tree(value, pos*2+2, mid+1, right, index, new_value)
    value[pos] = value[pos*2+1] + value[pos*2+2]

class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            return
        self.__value = [0] * len(nums) * 3
        self.__right = len(nums) - 1
        build_segment_tree(self.__value, nums, 0, 0, self.__right)


    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        update_segment_tree(self.__value, 0, 0, self.__right, i, val)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return sum_segment_tree(self.__value, 0, 0, self.__right, i, j)