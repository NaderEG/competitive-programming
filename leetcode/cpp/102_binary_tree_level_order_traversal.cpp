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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> q;
        if(root) {
            q.push_back(root);
        }
        

        while(q.size()>0) {
            vector<TreeNode*> newQ;
            vector<int> layer;
            for(TreeNode* current : q) {
                layer.push_back(current->val);
                if(current->left) {
                    newQ.push_back(current->left);
                }
                if(current->right) {
                    newQ.push_back(current->right);
                }
            }
            q=newQ;
            result.push_back(layer);
        }
        return result;
    }
};
