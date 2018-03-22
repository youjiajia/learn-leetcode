#include <stdio.h>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target){
                if(nums[begin]<nums[mid]){
                    if(nums[begin] > target)begin = mid + 1;
                    else if(nums[begin] < target)end = mid - 1;
                    else return begin;
                }else if(nums[begin]>nums[mid])end = mid - 1;
                else begin = mid + 1;
            }else if(nums[mid] < target){
                if(nums[begin]<nums[mid])begin = mid + 1;
                else if(nums[begin]>nums[mid]){
                    if(nums[begin]>target)begin = mid + 1;
                    else if(nums[begin]<target)end = mid - 1;
                    else return begin;
                }
                else begin = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    int a[] = {5, 1, 3};
    std::vector<int> nums;
    for(int i=0;i<3;i++){nums.push_back(a[i]);}
    Solution s;
    int result = s.search(nums, 5);
    printf("%d\n", result);
}