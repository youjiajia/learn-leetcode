class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        j = 0
        result = 0
        maxlen = 0
        chardict = dict()
        for x in s:
            chardict[x] = chardict.get(x, 0) + 1
            if chardict[x] == 1:
                maxlen += 1
                if result < maxlen:result = maxlen
            else:
                while chardict[x]>1:
                    chardict[s[j]] -= 1
                    j += 1
                    maxlen -= 1
                maxlen += 1
        return result