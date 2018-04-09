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
    TreeNode* BSTsearch(TreeNode* root, int key, TreeNode* &nodeparent){
        if(root->val == key)return root;
        else if(root->val > key && root->left){
            nodeparent = root;
            return BSTsearch(root->left, key, nodeparent);
        }else if(root->val < key && root-> right){
            nodeparent = root;
            return BSTsearch(root->right, key, nodeparent);
        }
        return NULL;
    }

    TreeNode* find_successor(TreeNode* node, TreeNode* &nodeparent){
        nodeparent = node;
        TreeNode* ptr = node->right;
        while(ptr->left){
            nodeparent = ptr;
            ptr = ptr->left;
        }
        return ptr;
    }

    void delete_node(TreeNode *sucessor_node, TreeNode *nodeparent){
        if(sucessor_node->val > nodeparent->val){
            if(sucessor_node->left)nodeparent->right = sucessor_node->left;
            else if(sucessor_node->right)nodeparent->right = sucessor_node->right;
            else nodeparent->right = NULL;
        }else{
            if(sucessor_node->left)nodeparent->left = sucessor_node->left;
            else if(sucessor_node->right)nodeparent->left = sucessor_node->right;
            else nodeparent->left = NULL;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        TreeNode* nodeparent = NULL;
        TreeNode* node = BSTsearch(root, key, nodeparent);
        if(!node)return root;
        if(node->left&&node->right){
            TreeNode* successor_node = find_successor(node, nodeparent);
            delete_node(successor_node, nodeparent);
            node->val = successor_node->val;
            return root;
        }
        if(nodeparent){
            delete_node(node, nodeparent);
            return root;
        }
        if(node->left){
            root = root->left;
        }else{
            root = root->right;
        }
        return root;
    }
};