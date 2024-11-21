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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        TreeNode *current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                if (prev != nullptr && prev->val > current->val) {
                    if (first == nullptr) {
                        first = prev;
                        middle = current;
                    } else {
                        last = current;
                    }
                }
                prev = current;
                current = current->right;
            } else {
                TreeNode *predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    if (prev != nullptr && prev->val > current->val) {
                        if (first == nullptr) {
                            first = prev;
                            middle = current;
                        } else {
                            last = current;
                        }
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }

        if (first != nullptr && last != nullptr) {
            std::swap(first->val, last->val);
        } else if (first != nullptr && middle != nullptr) {
            std::swap(first->val, middle->val);
        }
    }
};
