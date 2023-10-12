#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

void printl(Node* &head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    cout<<endl;
}

void insertAtHead(int data, Node* &head)
{
    Node *temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertAtTail(int data, Node* &tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(int data, Node* &head, int pos){
    Node* temp= new Node(data);

    int i=1;
    while(i<pos-1){
        head=head->next;
        i++;
    }
    Node* temp1=head->next;
    head->next=temp;
    temp->prev=head;

    temp1->prev=temp;
    temp->next=temp1;

}

void deleteAtPos(int pos,Node* &head){

    int i=1;
    Node* p=head;
    Node* curr=head;

    while(i<pos){
        p=curr;
        curr=curr->next;
        i++;
    }
    if(curr->prev!=NULL){
    p->next=curr->next;
    }
    if(curr->next!=NULL){
    curr->next->prev=p;
    }
    curr->next=curr->prev=NULL;
    delete curr;


}

void numberOfNodes(Node* &head){
    int cnt=1;
    while(head->next!=NULL){
        head=head->next;
        cnt++;
    }
    cout<<cnt<<endl;
}

void middleLinkedList(Node* &head){
    Node* mid=head;
    int count=1;
    while(head!=NULL){
        mid=mid->next;
        head=head->next->next;
        count++;
    }

    cout<<count<<endl;
}

int main()
{

    Node *node1 = new Node(10);

    Node *head = node1;
    // cout << "head=" << head << endl;
    Node *tail = node1;

    insertAtHead(15, head);
    insertAtHead(12, head);



    // cout << "head=" << head << endl;

    insertAtTail(25, tail);
    insertAtPos(45,head, 2);
    // deleteAtPos(5,head);
    printl(head);

    numberOfNodes(head);

    middleLinkedList(head);

    return 0;
}