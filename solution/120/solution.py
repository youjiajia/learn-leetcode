class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) == 0:
            return 0
        result = [[] for x in xrange(len(triangle))]
        result[-1] = triangle[-1]
        for line in xrange(len(triangle)-2, -1, -1):
            for i in xrange(len(triangle[line])):
                result[line].append(min(result[line+1][i], result[line+1][i+1]) + triangle[line][i])
        return result[0][0]