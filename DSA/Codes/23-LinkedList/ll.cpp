#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

int length(Node* head){
    if(head == NULL)
        return 0;
    int cnt=0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtHead(Node* &head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int d){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *n = new Node(d);
    temp->next = n;
}

void insertAtMiddle(Node* &head, int p, int d){
    if(head == NULL || p==0){
        insertAtHead(head, d);
        return;
    }
    if(p >= length(head))
        insertAtTail(head, d);
    Node *n = new Node(d);
    Node *temp = head;
    while(p>1){
        p--;
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void deleteHead(Node* &head){
    if(head == NULL)
        return;
    Node* temp = head->next;
    delete head;
    head = temp;
}

void (Node* &head){
    if(head == NULL)
        return;
    if(head->next == NULL)
        deleteHead(head);
    Node *temp = head, *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}

void deleteMiddle(Node* &head, int p){
    if(head == NULL)
        return;
    if(p==0)
        deleteHead(head);
    if(p >= length(head))
        deleteTail(head);
    Node *temp=head, *prev=NULL;
    while(p>0){
        p--;
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

bool (Node *head, int key){
    if(head == NULL)
        return false;
    while(head != NULL){
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

bool searchLLRec(Node *head, int key){
    if(head == NULL)
        return false;
    if(head->data == key)
        return true;
    return searchLLRec(head->next, key);
}

Node* input(){
    Node* head = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream &is, Node* &head){
    head = input();
    return is;
}

ostream& operator<<(ostream &os, Node *head){
    print(head);
    return os;
}

void reverseLL(Node* &head){
    if(head == NULL)
        return;
    Node *prev=NULL, *c=head, *n;
    while(c!=NULL){
        n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }
    head = prev;
}

Node* reverseLLRec(Node* head){
    if(head->next == NULL || head == NULL)
        return head;
    Node* shead = reverseLLRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

Node* middleNode(Node* &head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* slow=head, *fast=head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* kthNode(Node* head, int k){
    if(k == 0)
        return head;
    Node *slow=head, *fast=head;
    while(k>=0){
        fast = fast->next;
        k--;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

// Both LL should be sorted
Node* merge2LL(Node* a, Node* b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    Node *c;
    if(a->data <= b->data){
        c=a;
        c->next = merge2LL(a->next, b);
    }
    else{
        c=b;
        c->next = merge2LL(a, b->next);
    }
    return c;
}

Node* mergeSort(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* mid = middleNode(head);
    Node* a=head, *b= mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge2LL(a, b);
}

// Floyd Cycle Detection
bool hasCycle(Node *head) {
        if(head==NULL || head->next==NULL)
            return false;
        Node *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
}

// Floyd Cycle Detection
Node *detectCycle(Node *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        Node *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast = head;
                while(fast!=slow){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    Node *head = NULL;

    // Length, Print, Insertion and Deletion
    insertAtHead(head, 2);
    insertAtHead(head, 7);
    insertAtMiddle(head, 1, 1);
    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 5);
    insertAtMiddle(head, 3, 6);
    insertAtHead(head, 8);
    insertAtHead(head, 0);
    insertAtTail(head, 4);
    cout<<"Length of LL: "<<length(head)<<endl;
    print(head);
    deleteTail(head);
    print(head);
    deleteHead(head);
    print(head);
    deleteMiddle(head, 3);
    print(head);

    // Search and Rec Search
    if(searchLL(head, 3)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;
    if(searchLL(head, 1)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;

    //Node* head1 = input();
    //print(head1);

    // operator Overloading
    //Node* head2 = NULL;
    //Node* head3 = NULL;
    //cin>>head1>>head2;
    //cout<<head1<<head2;

    print(head);
    reverseLL(head);
    print(head);
    head = reverseLLRec(head);
    print(head);
    //deleteTail(head);
    Node* midNode = middleNode(head);
    cout<<midNode->data<<endl;
    Node* kNode = kthNode(head, 3);
    print(kNode);
    Node* head4 = NULL, *head5 = NULL;
    cin>>head4>>head5;
    Node *mergeLL = merge2LL(head4, head5);
    cout<<mergeLL;
    head = mergeSort(head);
    cout<<head;

	return 0;
}
