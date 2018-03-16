
#include <string>
#include <stack>

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
        op.pop();
    }
    int calculate(std::string s) {
        std::stack<int> nums;
        std::stack<char> op;
        static const int BEGIN = 0;
        static const int NUM = 1;
        static const int SIGN = 2;
        int state = BEGIN;
        int calculate_flag = 0;
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
                        if(calculate_flag==1)complute(nums, op);
                        state = SIGN;
                        i--;
                    }
                    break;
                case SIGN:
                    if(s[i]=='+' || s[i]=='-'){
                        calculate_flag = 1;
                        op.push(s[i]);
                    }else if(s[i] == '('){
                        calculate_flag = 0;
                        state = NUM;
                    }else if(s[i] == ')'){
                        complute(nums, op);
                    }else if(s[i]>= '0'&& s[i]<= '9'){
                        state = NUM;
                        i--;
                    }
                    break;

            }
        }
        if(number!=0){nums.push(number);complute(nums, op);};
        if(nums.empty())return 0;
        return nums.top();
    }
};