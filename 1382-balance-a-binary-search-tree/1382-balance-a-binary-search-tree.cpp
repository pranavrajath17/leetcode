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
TreeNode* BSTfromsortedvec(vector<int>&nodes,int si,int ei){
    if(si>ei){
        return NULL;
    }
   int mid=si+(ei-si)/2;
   TreeNode* curr=new TreeNode(nodes[mid]);
   curr->left=BSTfromsortedvec(nodes,si,mid-1);
   curr->right=BSTfromsortedvec(nodes,mid+1,ei);
   return curr;
}
void inorder(TreeNode* root,vector<int> &nodes){
    if(root==NULL){
        return ;
    }
    inorder(root->left,nodes);
    nodes.push_back(root->val);
    inorder(root->right,nodes);
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nodes;
        inorder(root,nodes);
        return BSTfromsortedvec(nodes,0,nodes.size()-1);
    }
};