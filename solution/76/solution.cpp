class Solution {
public:
    string minWindow(string s, string t) {
        int j = 0;
        string result = "";
        int map_s[128] = {0};
        int map_t[128] = {0};
        vector<int> vec_t;
        for(int i = 0;i < t.length();i++){
            map_t[t[i]]++;
        }
        for(int i=0;i<128;i++){
            if(map_t[i]>0)vec_t.push_back(i);
        }
        for(int i=0;i<s.length();i++){
            map_s[s[i]]++;
            while(j<i){
                if(map_t[s[j]]==0){
                    j++;
                }else if(map_t[s[j]]<map_s[s[j]]){
                    map_s[s[j]]--;
                    j++;
                }else{break;}
            }
            if(isWindowOk(map_s, map_t, vec_t)){
                int newlen = i-j+1;
                if(result==""||newlen<result.length()){
                    result = s.substr(j, newlen);
                }
            }
        }
        return result;
    }
    bool isWindowOk(int map_s[], int map_t[], vector<int> &vec_t){
        for (int i = 0; i < vec_t.size(); i++){
            if (map_s[vec_t[i]] < map_t[vec_t[i]]){
                return false;
            }
        }
        return true;
    }
};