# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1:
            return l2
        if not l2:
            return l1

        p1 = l1
        p2 = l2

        newHead = ListNode((p1.val + p2.val) % 10)
        carry = (p1.val + p2.val)//10

        temp = newHead
        p1 = p1.next
        p2 = p2.next
        
        while p1 or p2:
            if not p1:
                sum1 = 0
            else:
                sum1 = p1.val
                p1 = p1.next

            if not p2:
                sum2 = 0
            else:
                sum2 = p2.val
                p2 = p2.next
            tsum = (sum1 + sum2 + carry)
            temp.next = ListNode(tsum % 10)
            carry = tsum // 10

            temp = temp.next

        if carry > 0:
            temp.next = ListNode(carry)

        return newHead
