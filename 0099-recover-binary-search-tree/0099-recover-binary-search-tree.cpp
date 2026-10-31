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
TreeNode* prev=NULL;//here it will automatically calculate go through the problem
TreeNode* first=NULL;
TreeNode* sec=NULL;
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    //finding the anamoly
    if(prev!=NULL && prev->val>root->val){
        //found the anamoly
        if(first==NULL){
            first=prev;
        }
        sec=root;
    }
    prev=root;
    inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        //we will travel travel in inorder traversal
        //we will get first and second which we will swap
        inorder(root);
        int temp=first->val;
        first->val=sec->val;
        sec->val=temp;

    }
};