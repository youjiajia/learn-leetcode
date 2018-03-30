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
    void flatten(TreeNode* root) {
        TreeNode *last=NULL;
        preorder(root, last);
    }
    void preorder(TreeNode* root, TreeNode*& last){
        if(!root)return;
        if(!root->left&&!root->right){
            last = root;
            return;
        }
        TreeNode *leftback = root->left;
        TreeNode *rightback = root->right;
        TreeNode *leftlast = NULL;
        TreeNode *rightlast = NULL;
        if(root->left){
            preorder(leftback, leftlast);
            root->right = leftback;
            root->left = NULL;
            last= leftlast;
        }
        if(rightback){
            preorder(rightback, rightlast);
            if(leftlast){
                leftlast->right = rightback;
            }
            last = rightlast;
        }
    }
    
};