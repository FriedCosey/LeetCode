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
        ListNode *cur, *tmp, *start;
        start = cur = new ListNode(0);
        if(head == NULL || head->next == NULL)
            return head;
        cur->next = head;
        while(cur->next && cur->next->next){
            tmp = cur->next->next;
            cur->next->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        return start->next;
    }
};
