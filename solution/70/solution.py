class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = [0] * n
        result[1] = 1
        result[2] = 2
        for i in xrange(3, n+1):
            result[i] = result[i-1] + result[i-2]
        return result[n]