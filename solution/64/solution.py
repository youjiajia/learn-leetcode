class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0:return 0
        result = [[] for _ in xrange(len(grid))]
        result[0].append(grid[0][0])
        for x in grid[0][1:]:
            result[0].append(result[0][-1]+x)
        for i in xrange(1, len(grid)):
            result[i].append(result[i-1][0] + grid[i][0])
            for j in xrange(1, len(grid[0])):
                result[i].append(grid[i][j] + min(result[i-1][j], result[i][j-1]))
        return result[-1][-1]