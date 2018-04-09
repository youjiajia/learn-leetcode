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
    void travel_sum(TreeNode* root, int &sum){
        if(!root){
            return;
        }
        travel_sum(root->right, sum);
        sum += root->val;
        root->val = sum;
        travel_sum(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        travel_sum(root, sum);
        return root;
    }
};