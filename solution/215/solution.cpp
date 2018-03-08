#include <stdio.h>
#include <vector>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
        for(int i=0;i<nums.size();i++){
            if(Q.size()<k){
                Q.push(nums[i]);
            }else if(Q.top()<nums[i]){
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};