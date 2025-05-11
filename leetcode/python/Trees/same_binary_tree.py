# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        pstack = []
        qstack = []

        plist = []
        qlist = []

        while True:
            if p:
                plist.append(p.val)
            else:
                plist.append(p)
            if p is not None:
                pstack.append(p)
                p = p.left
            
            elif(pstack):
                p = pstack.pop()
                p = p.right
            else:
                break

        while True:
            if q:
                qlist.append(q.val)
            else:
                qlist.append(q)
            if q is not None:
                qstack.append(q)
                q = q.left
            
            elif(qstack):
                q = qstack.pop()
                q = q.right
            else:
                break
        
        if len(plist) != len(qlist):
            return False
        for i in range(len(plist)):
            if plist[i] != qlist[i]:
                return False
        return True


