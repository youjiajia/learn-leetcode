#include <stdio.h>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> result(n, 0);
        result[1] = 1;
        result[2] = 2;
        for(int i=3;i<=n;i++){
            result[i] = result[i-1] + result[i-2];
        }
        return result[n];
    }
};


int main(){
    Solution solve;
    printf("%d\n", solve.climbStairs(3));
    return 0;
}