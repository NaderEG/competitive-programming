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
    ListNode* addTwoNumbers_helper(ListNode* l1, ListNode* l2, int carry_on) {
        if(!l1 && !l2) {
            if (carry_on == 0) {
                return nullptr;
            } else {
                return new ListNode(carry_on);
            }
        }

        ListNode* node = new ListNode((carry_on + l1->val + l2->val) % 10);
        node->next = addTwoNumbers_helper(l1->next, l2->next, (carry_on + l1->val + l2->val) / 10);
        return node;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1->next || p2->next) {
            if(!p1->next) {
                p1->next = new ListNode(0);
            }
            if(!p2->next) {
                p2->next = new ListNode(0);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return addTwoNumbers_helper(l1, l2, 0);
    }
};
