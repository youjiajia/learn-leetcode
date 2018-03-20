class Solution {
public:

    void generate(int i, vector<int>& nums, set<vector<int>>& res_set, vector<int>& item, int sum, int target, vector<vector<int>>& result){
        if(i>=nums.size()||sum > target)return;
        item.push_back(nums[i]);
        sum += nums[i];
        if(sum==target&&res_set.find(item)==res_set.end()){result.push_back(item);res_set.insert(item);}
        generate(i+1, nums, res_set, item, sum, target, result);
        sum -= nums[i];
        item.pop_back();
        generate(i+1, nums, res_set, item, sum, target, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;
        std::sort(candidates.begin(),candidates.end());
        generate(0, candidates, res_set, item, 0, target, result);
        return result;
    }
};