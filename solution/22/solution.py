class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        if n==0:return result
        generate('(', 1, 0, n, result)
        return result

    def generate(item, left_num, right_num, n, result):
        if left_num == right_num == n:
            result.append(item)
            return
        if left_num > n or right_num > left_num:
            return
        left_num += 1
        generate(item+'(', left_num, right_num, n, result)
        left_num -= 1
        right_num += 1
        generate(item+')', left_num, right_num, n, result)