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
    int global_max;
    int maxPathSum_helper(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int maxLeft = maxPathSum_helper(root->left);
        int maxRight = maxPathSum_helper(root->right);

        int local_max = root->val;
        local_max = max(local_max, local_max + maxLeft);
        local_max = max(local_max, local_max + maxRight);
        global_max = max(global_max, local_max);
        
        if(maxLeft > maxRight) {
            return max(root->val + maxLeft, root->val);
        } else {
            return max(root->val, root->val + maxRight); 
        }
    }
    int maxPathSum(TreeNode* root) {
        global_max = root->val;
        maxPathSum_helper(root);
        return global_max;

    }
};
