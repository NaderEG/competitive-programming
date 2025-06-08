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

    long long total_sum;
    long long product_max;
    const int MOD = 1e9 + 7;
    long long sumOfTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return root->val + sumOfTree(root->left) + sumOfTree(root->right);
    }

    long long maxProduct_helper(TreeNode* root) {
        if(!root) {
            return 0;
        }
        long long current_sum = root->val + maxProduct_helper(root->left) + maxProduct_helper(root->right);
        long long product = current_sum * (total_sum - current_sum);
        product_max = max(product, product_max);
        return current_sum;
    }

    int maxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }
        total_sum = sumOfTree(root);
        product_max = root->val;
        maxProduct_helper(root);
        return product_max % MOD;
    }
};