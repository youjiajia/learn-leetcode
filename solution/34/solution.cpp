#include <stdio.h>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        std::vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }

    int searchLeft(std::vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid==0||nums[mid-1]!=target)return mid;
                right = mid - 1;
            }
            else if(nums[mid] > target) right = mid -1;
            else left = mid + 1;
        }
        return -1;
    }

    int searchRight(std::vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid==nums.size()-1||nums[mid+1]!=target)return mid;
                left = mid + 1;
            }
            else if(nums[mid] > target)right = mid -1;
            else left = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution s;
}