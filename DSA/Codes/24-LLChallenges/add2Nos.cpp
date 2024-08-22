ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        ListNode *tempCopy = temp;
        int c=0;
        while(l1!=NULL || l2!=NULL || c>0){
            if(l1!=NULL){
                c += l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                c += l2->val;
                l2=l2->next;
            }
            tempCopy->next = new ListNode(c%10);
            c /= 10;
            tempCopy=tempCopy->next;
        }
        return temp->next;
    }