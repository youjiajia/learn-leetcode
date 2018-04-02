from collections import defaultdict as dfdict

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        charmap = dfdict(int)
        maxlength = 0
        flag = 0
        for x in s:
            charmap[x] += 1
        for k,v in charmap.items():
            if v % 2 == 0:
                maxlength += v
            else:
                flag = 1
                maxlength += v-1
        return maxlength + flag


s = Solution()
print s.longestPalindrome('abccccdd')