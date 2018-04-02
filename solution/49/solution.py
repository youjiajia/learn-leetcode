class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result = []
        groups = {}
        for x in strs:
            sortx = ''.join(sorted(x))
            if not groups.has_key(sortx):
                groups[sortx] = []
            groups[sortx].append(x)
        return [x for x in groups.values()]