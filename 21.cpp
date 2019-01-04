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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //special case
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *pnode = new ListNode(0), *rtn = pnode;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pnode->next = l1;
                l1 = l1->next;
            }
            else {
                pnode->next = l2;
                l2 = l2->next;
            }
            pnode = pnode->next;
        }
        pnode->next = l1 ? l1 : l2;
        return rtn->next;
    }
};