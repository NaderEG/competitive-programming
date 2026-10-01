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
    map<int, int> mapping;
    int preorderIndex = 0;
    TreeNode* buildTree_helper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderIndex]); 
        int inorderIndex = mapping[preorder[preorderIndex]];
        preorderIndex++;

        root-> left = buildTree_helper(preorder, inorder, left, inorderIndex-1);
        root-> right = buildTree_helper(preorder, inorder, inorderIndex+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
        return buildTree_helper(preorder, inorder, 0, inorder.size()-1);

    }
};
