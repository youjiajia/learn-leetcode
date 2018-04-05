class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)return 0;
        vector<vector<int> > result;
        for(int i=0;i<triangle.size();i++){
            vector<int> onelist;
            for(int j=0;j<triangle[i].size();j++){
                onelist.push_back(0);
            }
            result.push_back(onelist);
        }
        result[triangle.size()-1] = triangle[triangle.size()-1];
        for(int i = triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                result[i][j] = triangle[i][j] + min(result[i+1][j], result[i+1][j+1]);
            }
        }
        return result[0][0];
    }
};