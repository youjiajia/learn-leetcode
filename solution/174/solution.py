class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        if len(dungeon) == 0:return 0
        row = len(dungeon)
        column = len(dungeon[0])
        result = [[0]*column for _ in xrange(row)]
        result[-1][-1] = max(1, 1-dungeon[-1][-1])
        for i in xrange(column-2, -1, -1):
            result[-1][i] = max(1, result[-1][i+1] - dungeon[-1][i])
        for i in xrange(row-2, -1, -1):
            result[i][-1] = max(1, result[i+1][-1] - dungeon[i][-1])
            for j in xrange(column-2, -1, -1):
                result[i][j] = max(1, min(result[i+1][j], result[i][j+1]) - dungeon[i][j])
        return result[0][0]