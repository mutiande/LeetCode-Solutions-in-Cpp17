/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 || l2)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry == 1)
        {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};