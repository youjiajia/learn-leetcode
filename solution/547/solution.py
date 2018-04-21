class DisjointSet(object):
	def __init__(self, n):
		self.__ids = range(n)
		self.__size = [1] * n
		self.__count = n

	def count(self):
		return self.__count

	def find(self, p):
		while self.__ids[p] != p:
			self.__ids[p] = self.__ids[self.__ids[p]]
			p = self.__ids[p]
		return p

	def unions(self, p, q):
		i = self.find(p)
		j = self.find(q)
		if i==j:
			return
		if self.__size[i] < self.__size[j]:
			self.__ids[i] = self.__ids[j]
			self.__size[j] += self.__size[i]
		else:
			self.__ids[j] = self.__ids[i]
			self.__size[i] += self.__size[j]
		self.__count -= 1

class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        dj = DisjointSet(len(M))
        for i in xrange(len(M)):
        	for j in xrange(i+1, len(M)):
        		if M[i][j]:
        			dj.unions(i, j)
        return dj.count()