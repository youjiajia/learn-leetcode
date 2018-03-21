import copy
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result = []
        item = []
        onelines = ['.'*y + 'Q' + '.'*(n-y-1) for y in xrange(n)]
        marks = [[0]*n for _ in xrange(n)]
        self.complate(0, n, item, result, marks, onelines)
        return result

    def updatemark(self, x, y, marks):
        marks[x][y] = 1
        markx = [0, 0, 1, 1, 1, -1, -1, -1];
        marky = [-1, 1, 0, -1, 1, 0, -1, 1];
        n = len(marks)
        markn = max(n-x, x, n-y, y)
        for i in xrange(1, markn):
            for j in xrange(8):
                newx = x + i * markx[j]
                newy = y + i * marky[j]
                if newx >=0 and newx < len(marks) and newy >= 0 and newy < len(marks):
                    marks[newx][newy] = 1

    def complate(self, x, n, item, result, marks, onelines):
        if x == n:
            result.append(copy.copy(item))
            return
        for y in xrange(n):
            if marks[x][y] == 1:
                continue
            item.append(onelines[y])
            copymark = copy.deepcopy(marks)
            self.updatemark(x, y, marks)
            self.complate(x+1, n, item, result, marks, onelines)
            marks = copymark
            item.pop()

s = Solution()
print len(s.solveNQueens(9))