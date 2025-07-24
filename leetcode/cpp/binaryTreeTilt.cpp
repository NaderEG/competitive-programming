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
    int res = 0;
    int findTilt_helper(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftSum = findTilt_helper(root->left);
        int rightSum = findTilt_helper(root->right);
        res = res + abs(leftSum - rightSum);
        return leftSum+rightSum+root->val;
    }

    int findTilt(TreeNode* root) {
        findTilt_helper(root);
        return res;
    }
};