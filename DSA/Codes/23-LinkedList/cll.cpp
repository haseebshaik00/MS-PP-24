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

void insertAtHead(Node* &head, int d){
    if(head == NULL){
        head = new Node(d);
        head->next = head;
        return;
    }
    Node *n = new Node(d);
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

Node* getNode(Node* head, int d){
    if(head == NULL)
        return head;
    Node* temp = head;
    while(temp->next != head){
        if(temp->data == d)
            return temp;
        temp = temp->next;
    }
    if(temp->data == d)
        return temp;
    return NULL;
}

void deleteNode(Node* head, int d){
    if(head == NULL)
        return;
    Node *delNode = getNode(head, d);
    if(delNode == NULL)
        return;
    if(delNode == head)
        head = head->next;
    Node* temp = head;
    while(temp->next != delNode){
        temp = temp->next;
    }
    temp->next = delNode->next;
    delete delNode;
}

void print(Node *head){
    if(head == NULL)
        return;
    Node *temp = head;
    while(temp->next != head){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<"->HEAD"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 1);
    print(head);
    deleteNode(head, 4);
    print(head);

	return 0;
}
