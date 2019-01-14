/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //今天是2019年1月14日，刚考完马克思主义原理
 //今天第一次提交一次过，开心
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *last = NULL, *curr;
        while (head) {
            curr = head;
            head = head->next;
            curr->next = last;
            last = curr;
        }
        return last;
    }
};