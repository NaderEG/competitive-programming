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
    bool hasCycle(ListNode* head) {
        ListNode* bunny = head;
        ListNode* turtle = head;

        while(turtle && bunny) {
            turtle = turtle->next;
            if(bunny->next) {
                bunny = bunny->next->next;    
            }
            
            if (turtle == bunny) {
                return true;
            }
        }
        return false;
    }
};
