class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums[0];
        int index = 0;
        while(index <= max){
            if(max >= nums.size()-1){return true;}
            int number = nums[index] + index;
            if(number > max){max = number;}
            index ++;
        }
        return false;
    }
};