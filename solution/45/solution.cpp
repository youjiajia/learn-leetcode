class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2){return 0;}
        int max = nums[0];
        int index = 0;
        int standby = 0;
        int step = 1;
        while(index <= max){
            if(max >= nums.size()-1){return step;}
            if(standby >= nums.size()-1){return step+1;}
            int number = nums[index] + index;
            if(number > standby){standby = number;}
            if(index == max){
                max = standby;
                step ++;
            }
            index ++;
        }
        return -1;
    }
};