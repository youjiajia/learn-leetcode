struct GrapNode{
    int label;
    std::vector<GrapNode*> neighbors;
    GrapNode(int x):label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::vector<GrapNode*> nodes;
        std::vector<int> visits;
        for(int i=0;i<numCourses;i++){nodes.push_back(new GrapNode(i));visits.push_back(-1);}
        for(int i=0;i<prerequisites.size();i++){
            nodes[prerequisites[i].second]->neighbors.push_back(nodes[prerequisites[i].first]);
        }
        for(int i=0;i<nodes.size();i++){
            if(visits[i]==-1&&!DFS(nodes[i], visits)){
                return false;
            }
        }
        return true;
    }
    bool DFS(GrapNode *node, std::vector<int> &visits){
        visits[node->label]=0;
        for(int i=0;i < node->neighbors.size();i++){
            GrapNode* nownode = node->neighbors[i];
            if(visits[nownode->label] == 0)return false;
            else if(visits[nownode->label] == -1&&!DFS(nownode, visits))return false;
        }
        visits[node->label]=1;
        return true;
    }
};