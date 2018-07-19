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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre, *cur;
        pre = head;
        if(head == NULL || head->next == NULL)
            return pre;
        ListNode *tmp = head->next->next;
        cur = head->next;
        cur->next = pre;
        pre->next = swapPairs(tmp);
        return cur;
    }
};
