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
    ListNode* swap(ListNode *l1, ListNode *l2){
        l1->next = l2->next;
        l2->next = l1;
        return l2;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur, *start;
        start = cur = new ListNode(0);
        if(head == NULL || head->next == NULL)
            return head;
        cur->next = head;
        while(cur->next && cur->next->next){
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return start->next;
    }
};
