/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyList(Node* head) {
        if(head == nullptr) {
            return head;
        }
        Node* newNode = new Node(head->val);
        newNode->random = head->random;
        newNode->next = copyList(head->next);
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        // Loop through l1 to create l2, l2[i].random = l1[i].random
        Node* newHead = copyList(head);

        // Loop through l1 and l2 l1[i].next = l2[i]
        Node* l1 = head;
        Node* l2 = newHead;
        while(l1) {
            l1->random = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        // Loop through l2. l2[i].random = l2[i].random.next
        Node* current = newHead;
        while(current) {
            if(current->random) {
                current->random = current->random->random;
            }
            current = current->next;
        }
        return newHead;
    }
};
