/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

int *a = &p;
(a contains p's address)
int **b = &a;
(b contains a's address)
*b = &k;
a now points to k;

*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **p = &head, *pre, *cur;
        while((pre = *p) && (cur = (*p)->next)){
            pre->next = cur->next;
            cur->next = pre;
            *p = cur;
            p = &(pre->next);
        }
        return head;
    }
};
