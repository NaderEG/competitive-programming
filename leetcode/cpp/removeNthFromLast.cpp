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
    int counter = -1;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head) {
            head->next = removeNthFromEnd(head->next, n);
        }    
        counter++;    
        if(counter == n) {
            return head->next;
        }
        return head;
    }
};
