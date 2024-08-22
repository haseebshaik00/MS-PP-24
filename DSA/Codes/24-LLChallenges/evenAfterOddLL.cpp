Node* divide(Node* head) {
        if(head == NULL || head->next == NULL)
            return head;
        Node *oddMain = new Node(0), *evenMain = new Node(0), *temp=head;
        Node *odd = oddMain, *even=evenMain;
        while(temp!=NULL){
            if(temp->data%2 == 0){
                even->next = temp;
                even=even->next;
            }
            else{
                odd->next = temp;
                odd=odd->next;
            }
            temp = temp->next;
        }
        odd->next = NULL;
        even->next = oddMain->next;
        return evenMain->next;
    }