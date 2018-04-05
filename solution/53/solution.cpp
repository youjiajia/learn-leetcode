class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> datas(nums.size(), 0);
        int result=nums[0];
        datas[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            datas[i] = max(nums[i], datas[i-1] + nums[i]);
            if(datas[i]>result){
                result = datas[i];
            }
        }
        return result;
    }
};