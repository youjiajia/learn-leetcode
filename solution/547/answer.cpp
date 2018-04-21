
class Solution {
public:
    void DFS_graph(int u, vector<vector<int> > &M, vector<int> &visit){
        visit[u] = 1;
        for(int i=0;i<M.size();i++){
            if(visit[i]==0&&M[u][i]==1){
                DFS_graph(i, M, visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        std::vector<int> visit(M.size(), 0);
        int count = 0;
        for(int i=0;i<visit.size();i++){
            if(!visit[i]){
                DFS_graph(i, M, visit);
                count++;
            }
        }
        return count;
    }
};