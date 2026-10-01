# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        current = root
        while True:
            if not self.sameNext(current, p, q):
                return current
            if p.val >= current.val:
                current = current.right
            else:
                current = current.left
            
    
    def sameNext(self, root, p, q):
        if p.val == root.val and q.val != root.val:
            return False
        if p.val != root.val and q.val == root.val:
            return False
        if p.val > root.val and q.val < root.val:
            return False
        if p.val < root.val and q.val > root.val:
            return False
        return True