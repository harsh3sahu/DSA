#include<iostream>

using namespace std;


class node{

    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }


};


void inserthead(node* &head,int data){

    node* temp=new node(data);
    temp->next=head;
    head=temp;
    
}

void printLinkedList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void reverseLinkedList(node* &curr, node* &forward, node* &prev, node* &head){

    if(curr==NULL){
        return ;
    }

    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;

    reverseLinkedList(curr,forward,prev,head);

    head=prev;
    
}

void midLinkedList(node* &head, node* &mid){
    node* fast=head;
    node* slow=head;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    mid =slow;
}

bool checkcircular(node* head){
    node* temp=head;

    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;
        cout<<"check point 1\n";
    }

    if(temp->next==NULL){
        return false;
    }
    else{
        return true;
    }


}

int main(){

    node* head=new node(10);
    inserthead(head,15);
    inserthead(head,20);

    printLinkedList(head);
    // node* prev=NULL;

    // reverseLinkedList(head,head,prev,head);

    // printLinkedList(head);

    // node* mid;
    // midLinkedList(head,mid);

    // cout<<mid->data;

    cout<<"checking circular\n";

    bool cir=checkcircular(head);

    cout<<"is linkedlist circular"<< cir<<endl;




    return 0;
}