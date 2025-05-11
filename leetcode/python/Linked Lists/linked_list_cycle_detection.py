class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = head
        f = head

        while f.next:
            s = s.next
            f = f.next.next

            if not f:
                return False

            if s==f:
                return True
        
        return False
