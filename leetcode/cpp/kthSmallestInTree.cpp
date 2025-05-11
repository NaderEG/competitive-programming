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
    int result;
    int cnt = 0;
    void kthSmallest_helper(TreeNode* root, int k) {
        if(root->left) {
            kthSmallest_helper(root->left, k);
        }
        cnt++;
        if(cnt == k) {
            result = root->val;
        }
        if(root->right) {
            kthSmallest_helper(root->right, k);
        }

    }
    int kthSmallest(TreeNode* root, int k) {
        kthSmallest_helper(root, k);
        return result;
    }
};
