/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int now = 0;
        vector<vector<int> > result;
        vector<int> path;
        getPath(root, now, sum, result, path);
        return result;
    }
    void getPath(TreeNode* root,int &now, int sum, vector<vector<int> >&result, vector<int>&path){
        if(!root)return;
        now += root->val;
        path.push_back(root->val);
        if(!root->left&&!root->right&&now==sum)result.push_back(path);
        getPath(root->left, now, sum, result, path);
        getPath(root->right, now, sum, result, path);
        now -= root->val;
        path.pop_back();
    }
};