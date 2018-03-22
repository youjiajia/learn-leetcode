#include <stdio.h>
#include <vector>


class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        std::vector<int> result;
        std::vector<std::pair<int, int> > vec;
        for(int i=0;i<nums.size();i++){
            result.push_back(0);
            vec.push_back(std::make_pair(nums[i], i));
        }
        sortnum(vec, result);
        return result;
    }

    void sortnum(std::vector<std::pair<int, int> > &vec, std::vector<int> &result){
        if(vec.size()<2)return;
        int mid = vec.size() / 2;
        std::vector<std::pair<int, int> > fisrtvec;
        std::vector<std::pair<int, int> > secondvec;
        for(int i=0;i<mid;i++){
            fisrtvec.push_back(vec[i]);
        }
        for(int i=mid;i<vec.size();i++){
            secondvec.push_back(vec[i]);
        }
        sortnum(fisrtvec, result);
        sortnum(secondvec, result);
        int i = 0;
        int j = 0;
        vec.clear();
        while(i<fisrtvec.size()&&j<secondvec.size()){
            if(fisrtvec[i].first<=secondvec[j].first){
                vec.push_back(fisrtvec[i]);
                result[fisrtvec[i].second] += j;
                i++;
            }else{
                vec.push_back(secondvec[j]);
                j++;
            }
        }
        while(i<fisrtvec.size()){
            vec.push_back(fisrtvec[i]);
            result[fisrtvec[i].second] += j;
            i++;
        }
        while(j<secondvec.size()){
            vec.push_back(secondvec[j]);
            j++;
        }
    }
};

int main(){
    int test[]= {5, -7, 9, 1, 3, 5, -2, 1};
    std::vector<int> nums;
    for(int i=0;i<8;i++)nums.push_back(test[i]);
    Solution s;
    std::vector<int> result = s.countSmaller(nums);
    for(int i =0;i<result.size();i++){
        printf("[%d]", result[i]);
    }
    printf("\n");
    return 0;
}