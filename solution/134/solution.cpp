#include <stdio.h>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int sum_remain = 0;
        int max_gas_sum = 0;
        int max_gas_begin = 0;
        for(int i=0;i<gas.size();i++){
            int once_remain = gas[i] - cost[i];
            sum_remain += once_remain;
            max_gas_sum += once_remain;
            if(max_gas_sum<0){
                max_gas_sum=0;
                max_gas_begin = i + 1;
            }
        }
        if(sum_remain>=0)return max_gas_begin;
        return -1;
    }
};

int main(){
    std::vector<int> gas;
    gas.push_back(6);
    gas.push_back(1);
    gas.push_back(4);
    gas.push_back(3);
    gas.push_back(5);
    std::vector<int> cost;
    cost.push_back(3);
    cost.push_back(8);
    cost.push_back(2);
    cost.push_back(4);
    cost.push_back(2);
    Solution s;
    int i = s.canCompleteCircuit(gas, cost);
    printf("%d\n", i);
}