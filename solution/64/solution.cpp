class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        vector<vector<int> > result;
        result.push_back(grid[0]);
        for(int i = 1;i < grid[0].size();i++){
            result[0][i] = grid[0][i] + result[0][i-1];
        }
        for(int i = 1;i < grid.size();i++){
            result.push_back(vector<int>());
            result[i].push_back(result[i-1][0] + grid[i][0]);
            for(int j = 1;j < grid[i].size();j++){
                result[i].push_back(grid[i][j] + min(result[i-1][j], result[i][j-1]));
            }
        }
        return result[grid.size()-1][grid[0].size()-1];

    }
};