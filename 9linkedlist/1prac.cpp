#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }



};

void insertAtTail(Node* n1,int data){

    Node *n2=n1;

    while(n2->next!=NULL){
        n2=n2->next;
    }
    Node *temp=new Node(data);
    n2->next=temp;

}

void printLinkedList(Node* n1){
    while(n1->next!=NULL){
        cout<<n1->data<<endl;
        n1=n1->next;
    }
}

int main(){

    Node *n1= new Node(10);

    insertAtTail(n1,11);
    insertAtTail(n1,12);
    insertAtTail(n1,13);
    insertAtTail(n1,14);
    insertAtTail(n1,15);



    printLinkedList(n1);





    return 0;
}