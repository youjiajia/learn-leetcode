class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        int sum = 0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%4!=0)return false;
        int target = sum/4;
        int allnum = 1 << nums.size();
        vector<int> oresult;
        for(int x=0;x<allnum;x++){
            int itemsum = 0;
            for(int i=0;i<nums.size();i++){
                if(1<<i&x){itemsum+=nums[i];}
            }
            if(itemsum==target)oresult.push_back(x);
        }
        vector<int> tresult;
        for(int x=0;x<oresult.size();x++){
            for(int i=0;i<oresult.size();i++){
                if(oresult[x]&oresult[i])continue;
                tresult.push_back(oresult[x]|oresult[i]);
            }
        }
        for(int x=0;x<tresult.size();x++){
            for(int i=0;i<tresult.size();i++){
                if(tresult[x]&tresult[i])continue;
                return true;
            }
        }
        return false;
    }
};