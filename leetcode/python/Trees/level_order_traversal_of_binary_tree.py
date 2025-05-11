# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        plist = []
        if not root:
            return plist
        
        plist.append([root])

        for i in plist:
            newlist = []
            for j in i:
                if j.left:
                    newlist.append(j.left)
                if j.right:
                    newlist.append(j.right)
            if newlist:
                plist.append(newlist)
        
        res = []
        for x in plist:
            newList = []
            for y in x:
                newList.append(y.val)
            res.append(newList)
        return res

        
        
        