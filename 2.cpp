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
        int sum = l1->val + l2->val;
        int carry = sum / 10;
        ListNode *pnode = new ListNode(sum % 10), *rtn = pnode;
        while ((l1 && l1->next) || (l2 && l2->next)) {
            sum = ((l1 && l1->next) ? l1->next->val : 0) + ((l2 && l2->next) ? l2->next->val : 0) + carry;
            pnode = pnode->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1 ? l1->next : NULL, l2 = l2 ? l2->next : NULL;
        }
        if (carry) pnode->next = new ListNode(carry);
        return rtn;
    }
};