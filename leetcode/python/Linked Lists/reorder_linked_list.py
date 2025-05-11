# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        tail = head
        while tail.next:
            tail = tail.next
        
        p1 = head
        p2 = tail

        s = head
        f = head.next

        while f and f.next:
            f = f.next.next
            s = s.next
            
        reverser = s
        prev = None
        while reverser:
            next_node = reverser.next
            reverser.next = prev 
            prev = reverser
            reverser = next_node

        l = head
        r = tail

        while l and r:
            temp = l
            l = l.next
            temp.next = r

            temp = r
            r = r.next
            temp.next = l
        
        

            

        

        
        
        
