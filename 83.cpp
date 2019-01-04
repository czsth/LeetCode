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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode *pion = head, *last = head;
        int currval = head->val;
        while (pion = pion->next) {
            if (pion->val != currval) {
                //don't even free, sorry about that
                last = last->next = pion;
                currval = pion->val;
            }
        }
        last->next = NULL;
        return head;
    }
};