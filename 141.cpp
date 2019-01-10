/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //method of memory
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        set<ListNode *> mem;
        mem.insert(head);
        while ((head = head->next) != NULL) {
            if (mem.count(head)) return true;
            mem.insert(head);
        }
        return false;
    }
};

//method of diff-speed pointer
class Solution {
    inline bool goncheck(ListNode *&pnode, int step, ListNode *&other) {
        while (step--) {
            if (!(pnode = pnode->next) || pnode == other) return false;
        }
        return true;
    }
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *fast = head, *slow = head;
        while (true) {
            if (!goncheck(fast, 2, slow)){  //step 2, 3, or 4 doesn't really matter
                if (!fast) return false;
                else return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
