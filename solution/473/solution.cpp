class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%4!=0)return false;
        int target = sum/4;
        int items[4] = {0};
        return generate(0, items, target, nums);
    }
    bool generate(int n, int items[], int target, vector<int>& nums){
        if(n>=nums.size())return items[0] == target&&items[1] == target&&items[2] == target&&items[3] == target;
        for(int i=0;i<4;i++){
            items[i] += nums[n];
            if(items[i]<=target){
                if(generate(n+1,items,target,nums))return true;
            }
            items -= nums[n];
        }
        return false;
    }
};