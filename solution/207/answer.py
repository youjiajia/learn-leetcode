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
        degrees = []
        for i in xrange(numCourses):
            grapNodes.append(GrapNode(i))
            degrees.append(0)
        for x in prerequisites:
            grapNodes[x[1]].neighbors.append(grapNodes[x[0]])
            degrees[x[0]] += 1
        queue = [grapNodes[i] for i in xrange(len(degrees)) if degrees[i] == 0]
        while len(queue) != 0:
            node = queue[0]
            del queue[0]
            for x in node.neighbors:
                degrees[x.label] -= 1
                if degrees[x.label] == 0:
                    queue.append(x)
        for x in degrees:
            if x:
                return False
        return True

