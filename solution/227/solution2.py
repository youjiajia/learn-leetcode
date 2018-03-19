class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack, num, sign = [0], 0, '+'
        for i in xrange(len(s)):
            value = s[i]
            if value.isdigit():
                num = num*10 + ord(value) - ord('0')
            if (not value.isdigit() and not value.isspace()) or (i == len(s)-1):
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack.append(stack.pop()*num)
                elif sign == '/':
                    temp = stack.pop()
                    if temp <0 and temp%num !=0:
                        stack.append(temp/num+1)
                    else:
                        stack.append(temp/num)
                num = 0
                sign = value
        return sum(stack)

if __name__ == '__main__':
    s = Solution()
    print s.calculate("14-3/2");