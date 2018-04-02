from collections import defaultdict
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        result = ''
        char_t = defaultdict(int)
        char_s = defaultdict(int)
        for x in t:
            char_t[x] += 1
        begin = 0
        for i, v in enumerate(s):
            char_s[v] += 1
            while begin < i:
                if char_t[s[begin]] == 0:
                    begin += 1
                elif char_s[s[begin]] > char_t[s[begin]]:
                    char_s[s[begin]] -= 1
                    begin += 1
                else:
                    break
            if self.is_Window_Ok(char_s, char_t) and (result == '' or i-begin+1 < len(result)):
                result = s[begin: i+1]
        return result


    def is_Window_Ok(self, char_s, char_t):
        for k,v in char_t.items():
            if char_t[k] > char_s[k]:
                return False
        return True

s = Solution()
print s.minWindow("ab", 'a')