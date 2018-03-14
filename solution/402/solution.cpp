#include <stdio.h>
#include <vector>
#include <string>

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> S;
        std::string result = "";
        for(int i=0;i<num.length();i++){
            int number = num[i] - '0';
            while(k>0&&S.size()!=0&&number<S[S.size()-1]){
                S.pop_back();
                k--;
            }
            if(number!=0||S.size()>0){
                S.push_back(number);
            }
        }
        while(k>0&&S.size()>0){
            S.pop_back();
            k--;
        }
        for(int i=0;i<S.size();i++){
            result.append(1, '0' + S[i]);
        }
        if(result==""){
            result = "0";
        }
        return result;
    }
};