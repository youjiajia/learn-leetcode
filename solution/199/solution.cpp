#include <stdio.h>
#include <queue>
#include <vector>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int> > nodequeue;
        std::vector<int> result;
        if(root)nodequeue.push(std::make_pair(root, 0));
        while(!nodequeue.empty()){
            TreeNode* node = nodequeue.front().first;
            int deep = nodequeue.front().second;
            nodequeue.pop();
            if(result.size()==deep)result.push_back(node->val);
            else result[deep] = node->val;
            if(node->left)nodequeue.push(std::make_pair(node->left, deep+1));
            if(node->right)nodequeue.push(std::make_pair(node->right, deep+1));
        }
        return result;
    }
};