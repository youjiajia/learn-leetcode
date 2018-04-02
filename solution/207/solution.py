class GrapNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        grapNodes = []
        visits = []
        for i in xrange(numCourses):
            grapNodes.append(GrapNode(i))
            visits.append(-1)
        for x in prerequisites:
            grapNodes[x[1]].neighbors.append(grapNodes[x[0]])
        for x in grapNodes:
            if visits[x.label] == -1 and not self.DFS(x, visits):
                return False
        return True

    def DFS(self, node, visits):
        visits[node.label] = 0
        for x in node.neighbors:
            if visits[x.label] == 0:
                return False
            if visits[x.label] == -1 and not self.DFS(x, visits):
                return False
        visits[node.label] = 1
        return True
