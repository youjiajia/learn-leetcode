#include <stdio.h>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > result;
        std::vector<std::string> item;
        std::vector<std::string> nowboard;
        for(int i=0;i< n;i++){
            std::string s;
            for(int x=0;x< n;x++){
                s += '.';
            }
            nowboard.push_back(s);
            item.push_back(s);
        }
        complateNQueue(0, item, result, nowboard);
        return result;
    }
    void updateboard(std::vector<std::string>& nowboard, int x, int y){
        nowboard[x][y] = '1';
        static const int markx[] = {0, 0, 1, 1, 1, -1, -1, -1};
        static const int marky[] = {-1, 1, 0, -1, 1, 0, -1, 1};
        for(int i=0;i<nowboard.size();i++){
            for(int j=0;j<8;j++){
                int newx = x + markx[j]*i;
                int newy = y + marky[j]*i;
                if(newx>=0&&newx<nowboard.size()&&newy>=0&&newy<nowboard.size())nowboard[newx][newy]='1';
            }
        }
    }
    void complateNQueue(int x, std::vector<std::string>& item, std::vector<std::vector<std::string> >& result, std::vector<std::string>& nowboard){
        if(x== nowboard.size()){result.push_back(item);return;}
        for(int y=0;y<nowboard.size();y++){
            if(nowboard[x][y]=='1')continue;
            std::vector<std::string> copyboard = nowboard;
            item[x][y] = 'Q';
            updateboard(nowboard, x, y);
            complateNQueue(x+1, item, result, nowboard);
            nowboard = copyboard;
            item[x][y]='.';
        }
    }
};


int main(){
    Solution s;
    s.solveNQueens(1);
}