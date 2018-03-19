from collections import deque

class Solution(object):
    def compute(self, numstack, opstack):
        b = numstack.pop()
        a = numstack.pop()
        c = opstack.pop()
        if '+' == c:numstack.append(a+b)
        elif '-' == c:numstack.append(a-b)
        elif '*' == c:numstack.append(a*b)
        elif '/' == c:numstack.append(a/b)
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        numstack = deque()
        opstack = deque()
        number = 0
        level = {'+': 0, '-': 0, '*':1, '/':1}
        for i in s+'*1':
            if i == ' ':continue
            if i.isdigit():
                number = number*10 + ord(i) - ord('0')
                continue
            numstack.append(number)
            number = 0
            if len(opstack) == 0 or (level[i] > level[opstack[-1]]):
                opstack.append(i)
            else:
                while len(opstack)>0 and level[i] <= level[opstack[-1]]:self.compute(numstack, opstack)
                opstack.append(i)
        if number != 0: numstack.append(number)
        while len(opstack) != 0:self.compute(numstack, opstack)
        if len(numstack) == 0:return 0
        return numstack[0]

if __name__ == '__main__':
    s = Solution()
    print s.calculate("1*2-3/4+5*6-7*8+9/10");