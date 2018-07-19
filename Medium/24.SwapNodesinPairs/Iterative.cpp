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
        ListNode *pre, *start, *cur;
        start = new ListNode(0); 
        if(head == NULL || head->next == NULL)
            return head;
        pre = head, cur = head->next, start->next = cur;
        while(cur && pre){
            ListNode *tmp = cur->next;
            cur->next = pre;
            if(tmp && tmp->next) // even elements left
                cur = tmp->next, pre->next = tmp->next, pre = tmp;
            else if(tmp && tmp->next == NULL){ // odd elements
                pre->next = tmp;
                break;
            }
            else{ // no elements left
                pre->next = NULL;
                break;
            }
        }
        return start->next;
    }
};
