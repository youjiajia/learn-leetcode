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
    void BSTinsert(TreeNode *node, TreeNode *insert_node){
        if(insert_node->val < node->val){
            if(node->left){
                BSTinsert(node->left, insert_node);
            }else{
                node->left = insert_node;
            }
        }else{
            if(node->right){
                BSTinsert(node->right, insert_node);
            }else{
                node->right = insert_node;
            }
        }
    }

    void preorder_insert(std::vector<int> &nums, std::vector<TreeNode*> &nodelist, int begin, int end){
        if(end<begin)return;
        int mid = (begin + end) / 2;
        nodelist.push_back(new TreeNode(nums[mid]));
        preorder_insert(nums, nodelist, begin, mid-1);
        preorder_insert(nums, nodelist, mid+1, end);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        std::vector<TreeNode *> nodelist;
        preorder_insert(nums, nodelist, 0, nums.size() - 1);
        for(int i=1;i<nodelist.size();i++){
            BSTinsert(nodelist[0], nodelist[i]);
        }
        return nodelist[0];
    }


};
