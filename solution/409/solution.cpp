class Solution {
public:
    int longestPalindrome(string s) {
        int charmap[128] = {0};
        int flag = 0;
        int maxlegth=0;
        for(int i=0;i<s.length();i++){
            charmap[s[i]]++;
        }
        for(int i=0;i<128;i++){
            if(charmap[i]%2==0){
                maxlegth += charmap[i];
            }else{
                flag=1;
                maxlegth += charmap[i] - 1;
            }
        }
        return maxlegth+flag;
    }
};