/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //using set
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        set<ListNode *> s;
        s.insert(headA);
        while (headA = headA->next) s.insert(headA);
        if (s.count(headB)) return headB;
        while (headB = headB->next) if (s.count(headB)) return headB;
        return 0;
    }
};

//令两表长度相同，则同步前进时必然有结果
class Solution {
    int getLen(ListNode *pnode) {
        int sz  = 0;
        for (; pnode; pnode = pnode->next, ++sz) {}
        return sz;
    }
    
    inline void goStep(ListNode *&pnode, int step) {
        while (step--) pnode = pnode->next;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int szA = getLen(headA), szB = getLen(headB);
        if (szA > szB) goStep(headA, szA - szB);
        if (szB > szA) goStep(headB, szB - szA);
        for (; headA; headA = headA->next, headB = headB->next) {
            if (headA == headB) return headA;
        }
        return NULL;
    }
};

//保留headA, headB实现另类“差速指针”，类似141.环形链表追及问题
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while(a != b) {
            a = a? a->next : headB;
            b = b? b->next : headA;
        }
        return a;
    }
};