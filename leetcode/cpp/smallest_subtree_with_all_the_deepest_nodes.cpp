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
    unordered_map<int, set<int>> node_levels; // level, set of nodes at this level
    int max_level = 0;
    TreeNode* res = nullptr;
    void fillMap(TreeNode* root, int level) {
        if(!root) {
            return;
        }
        node_levels[level].insert(root->val);
        max_level = max(max_level, level);
        fillMap(root->left, level+1);
        fillMap(root->right, level+1);

    }

    int coverage(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int node_coverage;
        if(node_levels[max_level].contains(root->val)) {
            node_coverage = 1;
        } else {
            node_coverage = coverage(root->left) + coverage(root->right);
        }
        if(node_coverage == node_levels[max_level].size() && !res) {
            res = root;
        }
        return node_coverage;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        fillMap(root, 0);
        coverage(root);
        return res;
    }
};