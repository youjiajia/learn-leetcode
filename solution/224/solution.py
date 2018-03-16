from collections import deque
class Solution(object):
    def compute(self, nums, op):
        if(len(nums) < 2 or len(op) < 1):
            return
        b = nums.pop()
        a = nums.pop()
        if(op.pop()=='+'):nums.append(a+b)
        else:nums.append(a-b)


    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        BEGIN = 0
        SIGN = 1
        NUM = 2
        state = BEGIN
        number = 0
        calculate_flag = False
        nums = deque()
        op = deque()
        i = 0
        while i < len(s):
            if s[i] == ' ':
                i += 1
                continue
            if state == BEGIN:
                if s[i].isdigit():
                    state = NUM
                else:
                    state = SIGN
                i -= 1
            elif state == NUM:
                if s[i].isdigit():
                    number = number*10 + ord(s[i])-ord('0')
                else:
                    nums.append(number);
                    number = 0
                    if calculate_flag:self.compute(nums, op)
                    state = SIGN
                    i -= 1
            elif state == SIGN:
                if s[i].isdigit():
                    state = NUM
                    i -= 1
                elif s[i] == '(':
                    calculate_flag = False
                    state = NUM
                elif s[i] == '+' or s[i] == '-':
                    op.append(s[i])
                    calculate_flag = True
                elif s[i] == ')':
                    self.compute(nums, op)
            i += 1
        if number != 0:
            nums.append(number)
            self.compute(nums, op)
        if len(nums) == 0:
            return 0
        return nums[-1]


if __name__ == "__main__":
    s = Solution()
    print s.calculate("1+1")
