#include <stdio.h>
#include <vector>

class Solution {
public:
    void subsetstool(int i, std::vector<int>& nums, std::vector<int>& currentarray, std::vector<vector<int>>& result){
        if(i>=nums.size())return;
        currentarray.push_back(nums[i]);
        result.push_back(currentarray);
        subsetstool(i+1, nums, currentarray, result);
        currentarray.pop_back();
        subsetstool(i+1, nums, currentarray, result);
    }
    std::vector<vector<int>> subsets(std::vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> currentarray;
        result.push_back(currentarray);
        subsetstool(0, nums, currentarray, result);
        return result;
    }
};