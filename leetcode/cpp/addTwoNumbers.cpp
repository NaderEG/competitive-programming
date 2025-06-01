class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_on = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(l1 || l2 || carry_on) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry_on;
            current->next = new ListNode(sum % 10);
            current = current->next;
            carry_on = sum / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};