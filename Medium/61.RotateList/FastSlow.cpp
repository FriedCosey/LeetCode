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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;
        ListNode *tmp, *fast, *slow;
        fast = slow = tmp = head;
        int len = 0;
        while(tmp){
            tmp = tmp->next;
            len++;
        }
        if((!k % len))
            return head;
        for(int i = k % len; i > 0; i--){
            fast = fast->next;
        }
        while(fast->next != NULL)
            fast = fast->next, slow = slow->next;
        // start from slow->next
        fast->next = head;
        tmp = slow->next;
        slow->next = NULL;
        return tmp;
    }
};
