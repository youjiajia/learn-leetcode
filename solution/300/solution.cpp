class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        vector<int> result(nums.size(), 1);
        int max=1;
        for(int i = 1;i < nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && result[j] + 1 > result[i]){
                    result[i] = result[j] + 1;
                    if(max<result[i])max = result[i];
                }
            }
        }
        return max;
    }
};