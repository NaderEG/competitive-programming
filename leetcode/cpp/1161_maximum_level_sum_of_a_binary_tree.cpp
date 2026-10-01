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
    unordered_map<int, int> aux;
    int max_level = 0;

    void dfs(TreeNode* root, int level) {
        max_level = max(level, max_level);
        if(!root) {
            return;
        }

        aux[level] += root->val;
        dfs(root->left, level+1);
        dfs(root->right, level+1);

    }

    int maxLevelSum(TreeNode* root) {
        dfs(root, 0);
        int res = 0;
        int curr_max = root->val;
        for(int i = 0; i < max_level; i++) {
            if(aux[i] > curr_max) {
                res = i;
                curr_max = aux[i];
            }
        }
        return res+1;
    }
};