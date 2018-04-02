class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0;
        int longest = 0;
        int lenword = 0;
        int char_map[128] = {0};
        for(int i=0;i<s.length();i++){
            if(char_map[s[i]] == 0){
                char_map[s[i]]++;
                lenword ++;
                if(lenword>longest)longest = lenword;
            }else{
                while(s[i] != s[j]){
                    char_map[s[j]]--;
                    lenword--;
                    j++;
                }
                j++;
            }
        }
        return longest;
    }
};