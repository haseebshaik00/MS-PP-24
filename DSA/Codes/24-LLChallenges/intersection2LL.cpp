ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *a=headA, *b=headB;
        while(a!=b){
            a = (a==NULL) ? headB : a->next;
            b = (b==NULL) ? headA : b->next;
        }
        return a;
    }