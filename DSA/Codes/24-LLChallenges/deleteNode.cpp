void deleteNode(ListNode* node) {
        ListNode *temp = node, *prev=NULL;
        while(temp->next!=NULL){
            temp->val = temp->next->val; 
            prev=temp;
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
    }