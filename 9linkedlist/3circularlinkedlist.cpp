#include <iostream>
#include<map>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){

        this->data=data;
        this->next=this;
    }

     ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
     }
};


void deleteNode(int element, Node* &head){

    Node* temp= head;
    Node* curr=temp->next;


    while(curr->data!=element){
        temp=curr;
        curr=curr->next;
    }

    temp->next=curr->next;
    curr->next=NULL;
    delete curr;



}

void insertAt(int data, int element, Node* &head){

    Node* curr= head;    
    while(curr->data != element){
        curr=curr->next;
    }

    Node* temp=new Node(data);

    temp->next=curr->next;
    curr->next=temp;

    
}

void printCircular(Node* &head){
    Node* temp=head;
    
    do{
        cout<<temp->data<<endl;
        temp=temp->next;
        
    }while(temp!= head);


}

bool checkCircular(Node* head){

    Node* temp=head->next;

    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;
    }

    if(temp->next==NULL){
        return false;
    }

    if(temp->next==head){
        return true;
    }
    return false;

}
bool checkLoop(Node* head){
    map<Node* , bool> visited;

    Node* temp=head;
    while(temp->next!= NULL){
        visited[temp]=true;

        if(visited[temp->next]==true){
            return temp->next;
        }

        temp=temp->next;
        
    }
    return false;
} 

bool checkLoopCycle(Node* head){

    Node* fast=head;
    Node* slow=head;

    while(fast->next!=NULL &&fast !=NULL && fast!=slow){
        fast=fast->next->next;
        slow=slow->next;
    }

    if(fast->next==NULL){
        return false;
    }
    return true;

    
}



int main(){


    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    // printCircular(head,1);
    
    insertAt(15,10,head);

    insertAt(25,15,head);

    printCircular(node1);
 
    deleteNode(15,head);
    cout<<"node deleted"<<endl;
    printCircular(node1);


    bool ans=checkCircular(head);
    if(ans==1){
        cout<<"it is circular\n";
    }
    else{
        cout<<"the list is not circular\n";
    }

    //  bool l=checkLoop(head);
    cout<<"we are detecting a loop \n";
    // if(l){
    //     cout<<"it has a loop"<<endl;
    // }
    // else {
    //     cout<<"it does not contain loop\n";
    // }


    
     bool l=checkLoopCycle(head);
    cout<<"we are detecting a loop \n";
    if(l){
        cout<<"it has a loop"<<endl;
    }
    else {
        cout<<"it does not contain loop\n";
    }


    return 0;
}