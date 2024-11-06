Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> m;
        Node* newHead=new Node(head->val), *temp=head, *temp1=head;
        m.insert({head, newHead});
        Node* newTemp = newHead, *newTemp1=newHead;
        temp = temp->next;
        while(temp){
            Node* n = new Node(temp->val);
            m.insert({temp, n});
            newTemp->next = n;
            temp=temp->next;
            newTemp=newTemp->next;
        }
        while(temp1){
            if(temp1->random)
                newTemp1->random = m[temp1->random];
            newTemp1 = newTemp1->next;
            temp1 = temp1->next;
        }
        return newHead;
    }