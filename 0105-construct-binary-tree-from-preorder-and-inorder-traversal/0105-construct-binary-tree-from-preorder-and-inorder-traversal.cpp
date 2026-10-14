/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int search(vector<int>& inorder,int left,int right,int value){
    for(int i=left;i<=right;i++){
        if(inorder[i]==value){
            return i;
        }
    }
    return -1;
}
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preindx,int left,int right){
        if(left>right){
            return NULL;
        }
            TreeNode* root=new TreeNode(preorder[preindx]);
            int inindx=search(inorder,left,right,preorder[preindx]);
            preindx++;
         root->left=   helper(preorder,inorder,preindx,left,inindx-1);
         root->right=   helper(preorder,inorder,preindx,inindx+1,right);
         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindx=0;
       return helper(preorder,inorder,preindx,0,inorder.size()-1);
    }
};