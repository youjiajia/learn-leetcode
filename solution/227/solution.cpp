#include <stdio.h>
#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stack;
        stack.push(0);
        int num = 0;
        char sign = '+';
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9')num = num*10+s[i]-'0';
            if(((s[i]<'0'||s[i]>'9')&&s[i]!=' ')||i==s.length()-1){
                if(sign=='+')stack.push(num);
                else if(sign=='-')stack.push(-num);
                else if(sign=='*'){
                    int temp = stack.top();
                    stack.pop();
                    stack.push(temp*num);
                }else if(sign=='/'){
                    int temp = stack.top();
                    stack.pop();
                    stack.push(temp/num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int result = 0;
        while(!stack.empty()){
            int temp = stack.top();
            stack.pop();
            result += temp;
        }
        return result;
    }
};


int main(){
    std::string str = " 3/2 ";
    Solution s;
    int x = s.calculate(str);
    printf("%d\n", x);
}