class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        if len(s) < 10:return result
        charlist = ['A', 'C', 'G', 'T']
        temp = 0
        hash_map = dict()
        for i in xrange(9, -1, -1):
            temp = (temp << 2) + charlist.index(s[i])
        hash_map[temp] = 1
        for x in s[10:]:
            temp = (temp >> 2) | (charlist.index(x) << 18)
            hash_map[temp] = hash_map.get(temp, 0) + 1
        for k, v in hash_map.items():
            if v > 1:
                getstr = ''
                data = k
                for _ in xrange(10):
                    getstr += charlist[data & 3]
                    data = data >> 2
                result.append(getstr)
        return result


s = Solution()
print s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")