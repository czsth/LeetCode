/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//第一次提交，单独考虑了head的问题，不够统一和谐
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *pnode = head;
        while (pnode->next) {
            if (pnode->next->val == val) {
                ListNode *tmp = pnode->next;
                pnode->next = tmp->next;
                delete tmp;
            }
            else pnode = pnode->next;
        }
        if (head->val == val) {
            pnode = head;
            head = head->next;
            delete pnode;
        }
        return head;
    }
};

//但如果一个实体非常大的时候，统一的写法又不太划算
//不过还是可以学习一下dummy head这种写法
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 虽然此种情况与下述代码是统一的，
        // 但由于使用ListNode实体，
        // 考虑到实际应用中对象可能很大
        // 单独考虑会节省一点时间
        if (!head) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pnode = &dummy;
        while (pnode->next) {
            if (pnode->next->val == val) {
                ListNode *tmp = pnode->next;
                pnode->next = tmp->next;
                delete tmp;
            }
            else pnode = pnode->next;
        }
        return dummy.next;
    }
};