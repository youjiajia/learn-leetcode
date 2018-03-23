#include <stdio.h>
#include <vector>
#include <queue>


bool judge(const std::pair<int,int> a, const std::pair<int ,int> b) {
    return a.first<b.first;
}

class Solution {
public:
    int findMaximizedCapital(int k, int W, std::vector<int>& Profits, std::vector<int>& Capital) {
        std::vector<std::pair<int,int> > newCapital;
        for(int i = 0;i < Capital.size();i++){
            newCapital.push_back(std::make_pair(Capital[i], Profits[i]));
        }
        std::sort(newCapital.begin(), newCapital.end(), judge);
        std::priority_queue<int> big_queue;
        int i = 0;
        while(k>0 && i<newCapital.size()){
            if(W>=newCapital[i].first){
                if(newCapital[i].second>0)big_queue.push(newCapital[i].second);
            }
            else if(big_queue.empty())break;
            else{
                W += big_queue.top();
                big_queue.pop();
                k--;
                i--;
            }
            i++;
        }
        while(k>0&&!big_queue.empty()){
            W += big_queue.top();
            big_queue.pop();
            k--;
        }
        return W;
    }
};