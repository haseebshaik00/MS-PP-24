ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy, *temp=head, *curr=NULL, *n=NULL;
        int c=0;
        while(temp != NULL){
            temp = temp->next;
            c++;
        }
        while(c>=k){
            curr = prev->next;
            n = curr->next;
            for(int i=1; i<k; i++){
                curr->next = n->next;
                n->next = prev->next;
                prev->next = n;
                n = curr->next;
            }
            prev = curr;
            c -= k;
        }
        return dummy->next;
    }