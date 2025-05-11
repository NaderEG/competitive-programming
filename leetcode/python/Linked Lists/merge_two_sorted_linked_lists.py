# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        p1 = list1
        p2 = list2
        
        if not p1:
            return p2
        if not p2:
            return p1
        
        if p1.val > p2.val:
            p2 = list1
            p1 = list2
        res = p1


        while p1 and p2:
            while p1.next and p1.next.val <= p2.val:
                p1 = p1.next
            temp = p1
            p1 = p1.next
            temp.next = p2

            temp = p2
            p2 = p1
            p1 = temp
        return res
            
                
                
                


