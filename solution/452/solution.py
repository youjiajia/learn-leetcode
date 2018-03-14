class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points) == 0:
            return 0
        points.sort(cmp=lambda x, y:x[0] - y[0])
        num = 1
        pointstart = points[0][0]
        pointend = points[0][1]
        for i in xrange(1, len(points)):
            if points[i][0] > pointend:
                num += 1
                pointstart = points[i][0]
                pointend = points[i][1]
            else:
                pointstart = points[i][0]
                if pointend > points[i][1]:
                    pointend = points[i][1]
        return num