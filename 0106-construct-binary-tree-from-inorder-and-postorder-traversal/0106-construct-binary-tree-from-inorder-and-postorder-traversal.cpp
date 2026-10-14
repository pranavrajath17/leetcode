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
int search(vector<int>& inorder, int left, int right, int value) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,
                     int& postindx, int left, int right) {

        if (left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postindx]);

        int inindx = search(inorder, left, right, postorder[postindx]);

        postindx--;

        root->right = helper(postorder, inorder, postindx, inindx + 1, right);
        root->left = helper(postorder, inorder, postindx, left, inindx - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int postindx = postorder.size() - 1;

        return helper(postorder, inorder, postindx, 0, inorder.size() - 1);
    }
};