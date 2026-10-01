# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        pstack = []
        p = root

        while True:
            if self.sameTree(p, subRoot):
                return True
            if p is not None:
                pstack.append(p)
                p = p.left
            
            elif(pstack):
                p = pstack.pop()
                p = p.right
            else:
                break
    
        return False
    def sameTree(self, s, t):
        if not s and not t:
            return True
        if s and t and s.val == t.val:
            return (self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right))
        return False