/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void toVector(ListNode *head, vector<int> &v) {
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        toVector(head, v);
        int len = v.size();
        if (len < 2) return true;
        for (int i = 0; i < len / 2; ++i) {
            if (v[i] != v[len - 1 - i]) return false;
        }
        return true;
    }
};




//下面看一个 8 ms 的魔法师
//他这个 findMid 函数很有趣，使用快慢指针找到二分点
//然后解释一下他这个“空间复杂度为 O(1)”：
//这个空间复杂度基本来源于 reverseList 这个函数
//由于这个函数符合“尾递归”的形式
//据说编译器很可能将其优化为一个类似迭代函数的形式
//这个 O(1) 就是这么来的


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

// O(n) 时间复杂度和 O(1) 空间复杂度解决此题
// 遍历总长度在3n/2
class Solution {
public:
    // 翻转中间及后续节点的指向(n/2)
    ListNode* reverseList(ListNode* first, ListNode * second)
    {
        if (second == NULL)
            return first;
        ListNode* third = second->next;
        second->next = first;
        if (third == NULL)
        {
            return second;
        }
        else
        {
            first = third->next;
            third->next = second;
        }
        return reverseList(third, first);
    }
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *second = head->next;
        head->next = NULL;
        return reverseList(head, second);
    }
    // 找到中间节点(n/2)
    ListNode * findMid(ListNode *head)
    {
        ListNode* low = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            low = low->next;
            fast = fast->next->next;
        }
        return low;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL ||head->next == NULL)
            return true;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * mid = findMid(dummy);
        ListNode * last = mid->next;
        mid->next = NULL;
        ListNode * tmpHead1 = reverseList(last);
        ListNode * tmpHead2 = head;
        // n/2
        while (tmpHead2 && tmpHead1)
        {
            if (tmpHead2->val != tmpHead1->val)
                return false;
            tmpHead2 = tmpHead2->next;
            tmpHead1 = tmpHead1->next;
        }
        return true;
    }
};