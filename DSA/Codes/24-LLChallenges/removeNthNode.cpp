ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode *slow = head, *fast = head;
        while(n--)
            fast = fast->next;
        if (fast == nullptr)
            return head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return head;
    }