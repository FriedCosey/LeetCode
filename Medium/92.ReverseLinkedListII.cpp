class Solution {
public:
    ListNode* reverseList(ListNode *head, int count){
        ListNode *pre = head, *cur = head->next;
        while(count--){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = cur;
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1;
        ListNode *start = head;
        while(head){
            if(m == 1){
                return reverseList(head, n-m);
            }
            if(i == m - 1){
                head->next = reverseList(head->next, n-m);
                break;
            }
            i++, head = head->next;
        }
        return start;
    }
};
