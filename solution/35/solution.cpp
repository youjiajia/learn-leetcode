class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return midfind(0, nums.size() - 1, target, nums);
    }

    int midfind(int left, int right, int target, vector<int>& nums){
        int mid = (left + right) / 2;
        if(nums[mid] == target)return mid;
        if(nums[mid] > target){
            if(mid==0||target<nums[mid-1])return mid;
            return midfind(left, mid-1, target, nums);
        }
        else{
            if(mid==nums.size()-1||target<nums[mid+1])return mid +1;
            return midfind(mid+1, right, target, nums);
        }
    }
};

