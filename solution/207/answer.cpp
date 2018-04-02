struct GrapNode{
    int label;
    std::vector<GrapNode*> neighbors;
    GrapNode(int x):label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::vector<GrapNode*> nodes;
        std::queue<GrapNode*> queueNodes;
        std::vector<int> degrees;
        for(int i=0;i<numCourses;i++){
            nodes.push_back(new GrapNode(i));
            degrees.push_back(0);
        }
        for(int i=0;i<prerequisites.size();i++){
            nodes[prerequisites[i].second]->neighbors.push_back(nodes[prerequisites[i].first]);
            degrees[prerequisites[i].first]++; 
        }
        for(int i=0;i<degrees.size();i++){
            if(degrees[i]==0)queueNodes.push(nodes[i]);
        }
        while(!queueNodes.empty()){
            GrapNode* node = queueNodes.front();
            queueNodes.pop();
            for(int i=0;i<node->neighbors.size();i++){
                degrees[node->neighbors[i]->label]--;
                if(degrees[node->neighbors[i]->label]==0)queueNodes.push(node->neighbors[i]);
            }
        }
        for(int i=0;i<degrees.size();i++){
            if(degrees[i]!=0)return false;
        }
        return true;
    }
};