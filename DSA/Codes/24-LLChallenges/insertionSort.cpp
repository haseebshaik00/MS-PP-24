ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = NULL, *next = NULL;
        while(head){
            temp = dummy;
            next = head->next;
            while(temp->next && head->val >= temp->next->val)
                temp=temp->next;
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }