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
    int good_nodes_helper(TreeNode* root, int max_val_in_path) {
        if(!root) {
            return 0;
        }
        if(root->val >= max_val_in_path) {
            return 1 + good_nodes_helper(root->left, root->val) + good_nodes_helper(root->right, root->val);
        }
        return good_nodes_helper(root->left, max_val_in_path) + good_nodes_helper(root->right, max_val_in_path);
    }

    int goodNodes(TreeNode* root) {
        return good_nodes_helper(root, -101);
    }
};
