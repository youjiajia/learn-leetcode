#include <stdio.h>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > subsets(std::vector<int>& nums) {
        int allnum = 1 << nums.size();
        std::vector<std::vector<int> > result;
        for(int i=0;i< allnum;i++){
            std::vector<int> item;
            for(int x = 0;x< nums.size();x++){
                int binx = 1 << x;
                if(binx&i){
                    item.push_back(nums[x]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};