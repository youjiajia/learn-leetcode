class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> strdict;
        int patterndict[128] = {0};
        int p = 0;
        string word;
        str.push_back(' ');
        for(int i=0;i < str.length();i++){
            if(str[i]==' '){
                if(p == pattern.length())return false;
                if(strdict.find(word)==strdict.end()){
                    if(patterndict[pattern[p]]!=0)return false;
                    strdict[word] = pattern[p];
                    patterndict[pattern[p]] = 1;
                }else{
                    if(pattern[p]!=strdict[word])return false;
                }
                word = "";
                p ++;
            }else{
                word.push_back(str[i]);
            }
        }
        if(p!=pattern.length()){
            return false;
        }
        return true;
    }
};