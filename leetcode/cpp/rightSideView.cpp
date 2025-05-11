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
    vector<int> concat_vectors(vector<int> v1, vector<int> v2) {
        std::vector<int> result = v1;
        result.insert(result.end(), v2.begin(), v2.end());
        return result;
    }

    int max_depth_reached = 0;
    vector<int> rightSideView_helper(TreeNode* root, int depth) {
        vector<int> result;
        if(!root) {
            return result;
        }
        if(depth > max_depth_reached) {
            result = {root->val};
            max_depth_reached = depth;
        }
        result = concat_vectors(result, rightSideView_helper(root->right, depth+1));
        result = concat_vectors(result, rightSideView_helper(root->left, depth+1));
        return result;
    }

    vector<int> rightSideView(TreeNode* root) {
        return rightSideView_helper(root, 1);
    }
};
