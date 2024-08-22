Node* merge(Node* a, Node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        Node *temp;
        if(a->data <= b->data){
            temp=a;
            temp->bottom = merge(a->bottom, b);
        }
        else{
            temp = b;
            temp->bottom = merge(a, b->bottom);
        }
        return temp;
    }

    Node *flatten(Node *root) {
        if(root->next == NULL)
            return root;
        Node *temp = flatten(root->next);
        return merge(root, temp);
    }