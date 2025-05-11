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
    bool isValidBST_helper(TreeNode* root, int min, int max) {
        if(!root) {
            return true;
        }
        return root->val > min && root->val < max && isValidBST_helper(root->left, min, root->val) && isValidBST_helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, -1001, 1001);
    }
};
