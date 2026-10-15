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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "null ";
        }
        //follow preorder traversal
        string ans=to_string(root->val)+ " ";
        ans+=serialize(root->left);
        ans+=serialize(root->right);
        return ans;
    }
    TreeNode* buildtree(istringstream &ss){
        string s;
        ss>>s;
        if(s=="null"){
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(s));
        node->left=buildtree(ss);
        node->right=buildtree(ss);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);//this is the function i am using
        return buildtree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));