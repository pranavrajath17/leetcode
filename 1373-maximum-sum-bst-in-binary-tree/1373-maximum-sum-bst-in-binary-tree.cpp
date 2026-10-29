#include<climits>
#include<algorithm>
using namespace std;
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
 struct Info {
        bool isBST;
        int min;
        int max;
        int sum;

        Info(bool isBST, int min, int max, int sum) {
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->sum = sum;
        }
    };

    int maxSum = 0;

    Info solve(TreeNode* root) {
        if (root == nullptr) {
            return Info(true, INT_MAX, INT_MIN, 0);
        }

        Info leftInfo = solve(root->left);
        Info rightInfo = solve(root->right);

        if (leftInfo.isBST &&
            rightInfo.isBST &&
            root->val > leftInfo.max &&
            root->val < rightInfo.min) {

            int currMin = min(root->val,
                              min(leftInfo.min, rightInfo.min));

            int currMax = max(root->val,
                              max(leftInfo.max, rightInfo.max));

            int currSum = root->val + leftInfo.sum + rightInfo.sum;

            maxSum = max(maxSum, currSum);

            return Info(true, currMin, currMax, currSum);
        }

        return Info(false, 0, 0, 0);
    }
    int maxSumBST(TreeNode* root) {
         maxSum = 0;
        solve(root);
        return maxSum;
    }
};