class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 4:return False
        nsum = sum(nums)
        if nsum % 4 != 0:return False
        target = nsum / 4
        nums.sort(reverse=True)
        return self.checknum(target, nums, 3)

    def checknum(self, target, nums, k):
        if k == 0:return True
        results = []
        self.addnums(0, 0, target, nums, [], results)
        for result in results:
            nownums = []
            for x in xrange(len(nums)):
                if x not in result:
                    nownums.append(nums[x])
            if self.checknum(target, nownums, k-1):
                return True
        return False


    def addnums(self, sumn, n, target, nums, item, results):
        if sumn + nums[n] == target:
            results.append(item + [n])
        elif sumn + nums[n] < target:
            for x in xrange(n+1, len(nums)):
                self.addnums(sumn+ nums[n], x, target, nums, item+ [n], results)