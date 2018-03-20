class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0)return result;
        string item = "(";
        int left_num = 1;
        int right_num = 0;
        generate(result, "(", n, left_num, right_num);
        return result;
    }

    void generate(vector<string>& result, string item,int n, int left_num, int right_num){
        if(left_num == n&&right_num == n){
            result.push_back(item);
            return;
        }
        if(left_num>n||right_num>left_num)return;
        left_num ++;
        generate(result, item+'(', n, left_num, right_num);
        left_num --;
        right_num ++;
        generate(result, item+')', n, left_num, right_num);
    }
};