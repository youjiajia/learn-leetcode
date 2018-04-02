class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > groups;
        vector<vector<string> > result;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            if(groups.find(str) == groups.end()){
                vector<string> item;
                groups[str] = item;
            }
            groups[str].push_back(strs[i]);
        }
        map<string, vector<string> > ::iterator it;
        for(it=groups.begin();it!=groups.end();it++){
            result.push_back((*it).second);
        }
        return result;
    }
};