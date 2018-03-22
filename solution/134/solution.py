class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        remain_gas = max_gas = begin = 0
        for i in xrange(len(gas)):
            local_remain = gas[i] - cost[i]
            remain_gas += local_remain
            max_gas += local_remain
            if max_gas < 0:
                max_gas = 0
                begin = i + 1
        if remain_gas >= 0:return begin
        return -1