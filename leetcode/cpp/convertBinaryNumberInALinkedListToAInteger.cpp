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
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int res = 0;
        
        int size = 0;
        while(curr) {
            size++;
            curr = curr->next;
        }
        curr = head;
        int count = size;
        while(curr) {
            res += curr->val * pow(2, count-1);
            count--;
            curr = curr->next;
        }
        return res;
    }
};