class Solution {
public:
    /*
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        if(head == NULL) 
            return NULL;
        ListNode *slow, *fast;
        slow = fast = head;
        fast = fast->next;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
