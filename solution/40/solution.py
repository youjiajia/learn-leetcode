import copy
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result = []
        items = [[]]
        for n in xrange(len(candidates)):
            if candidates[n] > target:
                break
            if n == 0 or candidates[n] != candidates[n-1]:
                l = 0
            else:
                l = oldl
            oldl = len(items)
            for x in xrange(l, len(items)):
                newlist = items[x]+[candidates[n]]
                newsum = sum(newlist)
                if newsum == target:
                    result.append(newlist)
                if newsum <= target:
                    items.append(newlist)
        return result

s = Solution()
print s.combinationSum2([4,1,1,4,4,4,4,2,3,5], 10)