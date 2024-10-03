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
    std::vector<std::vector<int>> closestNodes(TreeNode* root, std::vector<int>& queries) {
        std::vector<int> nodes;
        inorderTraversal(root, nodes);

        std::vector<std::vector<int>> result;
        result.reserve(queries.size());

        for (int q : queries) {
            int floor = -1;
            int ceil = -1;

            int left = 0, right = nodes.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nodes[mid] == q) {
                    floor = nodes[mid];
                    ceil = nodes[mid];
                    break;
                } else if (nodes[mid] < q) {
                    floor = nodes[mid];
                    left = mid + 1;
                } else {
                    ceil = nodes[mid];
                    right = mid - 1;
                }
            }

            result.push_back({floor, ceil});
        }

        return result;
    }

private:
    void inorderTraversal(TreeNode* node, std::vector<int>& nodes) {
        if (!node) return;
        inorderTraversal(node->left, nodes);
        nodes.push_back(node->val);
        inorderTraversal(node->right, nodes);
    }
};
