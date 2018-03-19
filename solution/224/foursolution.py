class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [[0]]
        signs = [1]
        num = 0
        sign = 1
        for i in '('+s+')':
            if i.isdigit():
                num = num *10 + ord(i) - ord('0')
            elif not i.isspace():
                if i == '+':
                    stack.append(stack.pop()+sign*num)
                    sign = 1
                elif i == '-':
                    stack.append(stack.pop()+sign*num)
                    sign = -1
                elif i == '(':
                    stack.append(0)
                    signs.append(sign)
                    sign = 1
                else:
                    stack.append(stack.pop()+sign*num)
                    stack.append(stack.pop()*signs.pop()+stack.pop())
                    sign = 1
                num = 0
        result = 0
        for (x, y) in zip(stack, signs):
            result += x*y
        return result


if __name__ == "__main__":
    s = Solution()
    print s.calculate("(3-(2-(5-(9-(4)))))")
