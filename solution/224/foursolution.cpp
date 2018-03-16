#include <stdio.h>
#include <string>
#include <stack>
#include <map>

class Solution {
public:
    void complute(std::stack<int> &nums, std::stack<char> &op) {
        if(nums.size()<2||op.size()<1)return;
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        if(op.top()=='+')nums.push(a+b);
        else if(op.top()=='-')nums.push(b-a);
        else if(op.top()=='*')nums.push(b*a);
        else if(op.top()=='/')nums.push(b/a);
        op.pop();
    }
    int calculate(std::string s) {
        std::stack<int> nums;
        std::stack<char> op;
        static const int BEGIN = 0;
        static const int NUM = 1;
        static const int SIGN = 2;
        std::map<char, int> slevel;
        slevel['+'] = 1;
        slevel['-'] = 1;
        slevel['*'] = 2;
        slevel['/'] = 2;
        int state = BEGIN;
        int number = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ')continue;
            switch(state){
                case BEGIN:
                    if(s[i]>= '0'&& s[i]<= '9'){
                        state = NUM;
                    }else{
                        state = SIGN;
                    }
                    i--;
                    break;
                case NUM:
                    if(s[i]>= '0'&& s[i]<= '9'){
                        number = number*10 + s[i] - '0';
                    }else{
                        nums.push(number);
                        number = 0;
                        state = SIGN;
                        i--;
                    }
                    break;
                case SIGN:
                    if(s[i]>= '0'&& s[i]<= '9'){
                        state = NUM;
                        i--;
                    }else{
                        if(op.empty()||s[i]=='('||op.top()=='('||slevel[s[i]]>slevel[op.top()]){
                            op.push(s[i]);
                        }else if(s[i]==')'){
                            while(op.top()!='('){complute(nums, op);}
                            op.pop();
                        }else{
                            while(!op.empty()&&op.top()!='('&&slevel[s[i]]<=slevel[op.top()]){complute(nums, op);}
                            op.push(s[i]);
                        }
                    }
                    break;

            }
        }
        if(number!=0){nums.push(number);complute(nums, op);};
        while(!op.empty())complute(nums, op);
        if(nums.empty())return 0;
        return nums.top();
    }
};

int main(){
    std::string str = "1+ 2-(4+6*5-12*(1+2))*5+10";
    Solution s;
    int x = s.calculate(str);
    printf("%d\n", x);
}