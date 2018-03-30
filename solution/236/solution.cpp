#include <stdio.h>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<std::vector<TreeNode*> > result;
        std::vector<TreeNode*> path;
        int finish=2;
        getCommonAncestor(root, p, q, result, path, finish);
        int i = 0;
        TreeNode *resultnode=0;
        while(i < result[0].size() && i < result[1].size()){
            if (result[0][i] == result[1][i]){
                resultnode = result[0][i];
            }
            i++;
        }
        return resultnode;
    }
    void getCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, std::vector<std::vector<TreeNode*> > &result, std::vector<TreeNode*> &path, int &finish){
        if(!root||!finish)return;
        path.push_back(root);
        if(root==p||root==q){result.push_back(path);finish--;}
        getCommonAncestor(root->left, p, q, result, path, finish);
        getCommonAncestor(root->right, p, q, result, path, finish);
        path.pop_back();
    }
};


int main(){
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;

    Solution solve;
    TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
    printf("lowestCommonAncestor = %d\n", result->val);
    // result = solve.lowestCommonAncestor(&a, &d, &z);
    // printf("lowestCommonAncestor = %d\n", result->val);
    // result = solve.lowestCommonAncestor(&a, &b, &y);
    // printf("lowestCommonAncestor = %d\n", result->val);

    return 0;
}
