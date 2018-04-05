class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> result(amount+1, -1);
        result[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int x=0;x < coins.size();x++){
                int coin = coins[x];
                if(coin<=i&&result[i-coin]!=-1){
                    int num = result[i-coin] + 1;
                    if(result[i] == -1|| result[i] > num){
                        result[i] = num;
                    }
                }
            }
        }
        return result[amount];
    }
};