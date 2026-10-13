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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<tuple<TreeNode*, int, int>> q;
        // node, level (row), vc (vertical column)

        map<int, map<int, multiset<int>>> nodes;
        // nodes[vc][level] = node values

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* currNode = get<0>(curr);
            int level = get<1>(curr);
            int vc = get<2>(curr);

            nodes[vc][level].insert(currNode->val);

            if (currNode->left != nullptr) {
                q.push({currNode->left, level + 1, vc - 1});
            }

            if (currNode->right != nullptr) {
                q.push({currNode->right, level + 1, vc + 1});
            }
        }

        for (auto colIt : nodes) {
            vector<int> column;

            for (auto levelIt : colIt.second) {
                for (int value : levelIt.second) {
                    column.push_back(value);
                }
            }

            ans.push_back(column);
        }

        return ans;
    }
};