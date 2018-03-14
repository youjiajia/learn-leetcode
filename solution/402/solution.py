class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        S = []
        result = ""
        for x in num:
            x = int(x)
            while k > 0 and len(S) >0 and S[-1] > x:
                k -= 1
                del S[-1]
            if x != 0 or len(S) !=0:
                S.append(x)
        while k > 0 and len(S) > 0:
            k -= 1
            del S[-1]
        for x in S:
            result += str(x)
        if result == "":
            result = "0"
        return result