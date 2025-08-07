/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int key;
    public boolean isUnivalTree_helper(TreeNode root) {
        if(root == null) {
            return true;
        }
        return root.val == key && isUnivalTree_helper(root.left) && isUnivalTree_helper(root.right);
    }
    public boolean isUnivalTree(TreeNode root) {
        key = root.val;
        return isUnivalTree_helper(root);
    }
}