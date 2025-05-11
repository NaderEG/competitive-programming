# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        sz = 0
        p = head
        if not p:
            return head

        while p.next:
            sz += 1
            p = p.next

        if sz < 1:
            return None
        print(sz-n)
        if sz - n + 1 == 0:
            return head.next
        
        count = 1
        temp = head
        p = head.next

        

        while count <= sz - n:
            temp = temp.next
            p = p.next
            count += 1

        if not p:
            temp.next = None
        else:
            temp.next = p.next

        return head



        