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

void deleteTail(Node* &head){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    Node *head = NULL;
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

	return 0;
}
