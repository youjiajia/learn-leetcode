class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result = []
        item = [-1] * n
        colums = [True] * n + [False]
        adds = [True] * n * 2
        reduces = [True] * n * 2
        x = y = 0
        while True:
            if colums[y] and adds[x+y] and reduces[y-x+n]:
                item[x] = y
                colums[y] = adds[x+y] = reduces[y-x+n] = False
                x += 1
                y = 0
                if x == n:
                    result.append(['.'*y + 'Q' + '.'*(n-y-1) for y in item])
            else:
                if y == n:
                    if x==0:
                        return result
                    x -= 1
                    y = item[x]
                    colums[y] = adds[x+y] = reduces[y-x+n] = True
                y += 1



s = Solution()
print len(s.solveNQueens(9))