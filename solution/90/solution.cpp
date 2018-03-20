class Solution {
public:

    void generate(int i, vector<int>& nums, set<vector<int>>& res_set, vector<int>& item, vector<vector<int>>& result){
        if(i>=nums.size())return;
        item.push_back(nums[i]);
        if(res_set.find(item)==res_set.end()){result.push_back(item);res_set.insert(item);}
        generate(i+1, nums, res_set, item, result);
        item.pop_back();
        generate(i+1, nums, res_set, item, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;
        result.push_back(item);
        std::sort(nums.begin(),nums.end());
        generate(0, nums, res_set, item, result);
        return result;
    }
};