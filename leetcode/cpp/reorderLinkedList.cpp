/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // Get Mid
        ListNode* turtle = head;
        ListNode* rabbit = head;

        while (rabbit->next && rabbit->next->next) {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }
        if (rabbit->next) {
            rabbit = rabbit->next;
        }
        ListNode* mid = turtle;
        ListNode* tail = rabbit;

        // Reverse tail end of list
        ListNode* current = mid;
        ListNode* previous = nullptr;

        while (current) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        // Step 2: Increase left and right pointers while making them 
        // point to each other until mid is reached

        // using head, tail, and mid
        ListNode* left = head;
        ListNode* right = tail;
        
        while(left && right) {
            ListNode* temp = left;
            left = left->next;
            temp->next = right;
            temp = right;
            right = right->next;
            temp->next = left;
        }


    }
};
