"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        newHead = Node(head.val)

        if not head.next:
            return newHead

        p = head.next
        prev = newHead
        
        while p:
            prev.next = Node(p.val)
            prev = prev.next
            p = p.next

        p = head
        np = newHead

        while p:
            np.random = p.random
            p = p.next
            np = np.next

        p = head
        np = newHead
        while p:
            p.random = np
            p = p.next
            np = np.next

        np = newHead

        while np:
            if np.random:
                np.random = np.random.random
            np = np.next

        return newHead
        




