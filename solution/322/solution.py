class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        result = [-1] * (amount + 1)
        result[0] = 0
        for i in xrange(1, amount+1):
            for x in coins:
                if x <= i and result[i-x] != -1:
                    if result[i] == -1 or result[i] > result[i-x] + 1:
                        result[i] = result[i-x] + 1
        return result[amount]