ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode* temp = head;
        int n=0;
        while(temp != NULL){
            n++;
            temp=temp->next;
        }
        k %= n;
        if(k==0) return head;
        k = n-k;
        temp = head;
        while(k>1){
            temp = temp->next;
            k--;
        }
        ListNode* nex = temp->next, *temp1=temp->next;
        temp->next = NULL;
        while(temp1->next != NULL)
            temp1=temp1->next;
        temp1->next = head;
        return nex;
    }