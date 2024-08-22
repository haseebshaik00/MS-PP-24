bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *slow=head, *fast=head, *prevSlow=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prevSlow = slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* n = slow, *prev=NULL;
        while(slow!=NULL){
            n = slow->next;
            slow->next = prev;
            prev = slow;
            slow = n;
        }
        prevSlow = prev;
        while(prev!=NULL){
            if(prev->val != head->val)
                return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }