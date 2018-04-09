/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void change_int_to_string(int num, string &str_val){
        string temp;
        while(num){
            temp += num%10 + '0';
            num = num/10;
        }
        for(int i=temp.length()-1;i>=0;i--){
            str_val += temp[i];
        }
        str_val += '#';
    }

    void preorder_serialize(TreeNode* root, string &str){
        if(!root)return;
        string str_val;
        change_int_to_string(root->val, str_val);
        str += str_val;
        preorder_serialize(root->left, str);
        preorder_serialize(root->right, str);

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        preorder_serialize(root, str);
        return str;
    }

    void BST_insert(TreeNode* node, TreeNode* insertnode){
        if(insertnode->val > node->val){
            if(node->right){
                BST_insert(node->right, insertnode);
            }else{
                node->right = insertnode;
            }
        }else{
            if(node->left){
                BST_insert(node->left, insertnode);
            }else{
                node->left = insertnode;
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        vector<TreeNode*> nodelist;
        int temp=0;
        for(int i=0;i<data.length();i++){
            if(data[i]!='#')temp = temp*10 + (data[i] - '0');
            else{
                nodelist.push_back(new TreeNode(temp));
                temp = 0;
            }
        }
        for(int i=1;i<nodelist.size();i++){
            BST_insert(nodelist[0], nodelist[i]);
        }
        return nodelist[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));