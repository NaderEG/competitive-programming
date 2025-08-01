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
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* current = dummy;
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        dfs(root->left);
        current->right = new TreeNode(root->val);
        current = current->right;
        dfs(root->right);

    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return dummy->right;
    }
};