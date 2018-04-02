class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strdict = {}
        patterndict = {}
        str += ' '
        temp = ''
        p = 0
        for v in str:
            if v == ' ':
                if p == len(pattern):
                    return False
                if strdict.has_key(temp):
                    if strdict[temp] != pattern[p]:
                        return False
                else:
                    if patterndict.has_key(pattern[p]):
                        return False
                    patterndict[pattern[p]] = 1
                    strdict[temp] = pattern[p]
                p += 1
                temp = ''
            else:
                temp += v
        if p != len(pattern):
            return False
        return True
                    