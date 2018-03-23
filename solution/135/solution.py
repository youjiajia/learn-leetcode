class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        if len(ratings) < 2 :return len(ratings)
        upcandy = [1] + [0] * (len(ratings)-1)
        downcandy = [0] * (len(ratings)-1) + [1]
        for i in xrange(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                upcandy[i] = upcandy[i-1] + 1
            else:
                upcandy[i] = 1
        for i in xrange(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i+1]:
                downcandy[i] = downcandy[i+1] + 1
            else:
                downcandy[i] = 1
        newlist = [max(x) for x in zip(upcandy, downcandy)]
        return sum(newlist)
s = Solution()
print s.candy([2,1])