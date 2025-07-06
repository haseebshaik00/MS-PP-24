#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next = head;
    head = n;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Node* head1 = input();
    // print(head1);
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;
    

    // operator Overloading
    
    cin>>head1>>head2;
    cout<<head1<<head2;

    return 0;
}