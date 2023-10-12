#include<iostream>
#include<map>
using namespace std;


class Node{

public:
int data;

Node* next;

Node(int data){
    this -> data= data;
    this -> next= NULL;
}


};


void inserthead(Node* &head, int data){

    Node* temp=new Node(data);
    temp->next = head;
    head = temp;

}

void inserttail(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;

}

void printLink(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

// Node* reverseLinkedList(Node* head){
//     Node* curr=head;
//     Node* prev=NULL;
//     Node* forward;

//     // curr->next=prev;
//     // prev=curr;
//     // curr=forward;
//     // forward=forward->next;

//     // while(curr!=NULL){
//     // forward=curr->next;
//     // curr->next=prev;
//     // prev=curr;
//     // curr=forward;
//     // }

//     return prev;
// }


void reverseLinkedList(Node* &head, Node* &curr, Node* &prev, Node* &forward){
    if (curr==NULL){
        return;
    }
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    

    reverseLinkedList(head,curr,prev,forward);


    head=prev;
}

int midLinkedList(Node* &head){
    Node*  curr=head;
    Node* forward=head;
    int cnt=0;
    while(forward!=NULL && forward->next!=NULL){
        cnt=cnt+2;
        curr=curr->next;
        forward=forward->next->next;
    }
    if (cnt%2==0){
        return cnt/2;
    }
    else{
        return (cnt/2)+1;
    }
}

Node* midLinkedListGroups(Node* head,int k){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    if(head==NULL){
        return NULL;
    }
    int i=0;
    while(curr!=NULL && i<k){

    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    i++;
    }
    

    if(forward != NULL){

    head->next=midLinkedListGroups(forward,k);
    }
    
    return prev;
    
    
    
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

}

bool checkLoop(Node* head){
    map<Node* , bool> visit;

    Node* temp=head;
    while(temp->next!= NULL){
        

        if(visit[temp->next]==true){
            return true;
        }
        visit[temp]=true;
        temp=temp->next;
        
    }
    return false;
}

void createLoop(Node* &head, Node* &tail){
    Node* temp=head;

    while(temp->next!=head->next){
    if (temp->next==NULL){
        temp->next=head->next;
        tail=temp->next;
    }
    temp=temp->next;
}
}

bool checkLoopCycle(Node* head){

    Node* fast=head;
    Node* slow=head;

    while(fast->next!=NULL &&fast !=NULL && fast!=slow){
        fast=fast->next->next;
        slow=slow->next;
    }

    if(fast->next==NULL|| fast->next->next==NULL){
        return false;
    }
    return true;

    
}

int main(){



    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;


    inserttail(tail,15);
    inserttail(tail,25);
    inserttail(tail,20);
    inserttail(tail,30);
    inserttail(tail,35);
    inserttail(tail,40);
    inserttail(tail,50);

    printLink(node1);




    // cout<<head<<endl;

    // printLink(node1);

    // cout<<"\nreverse\n";
    // Node* prev=NULL;
    // Node* forward=head->next;
    // Node* curr=head;

    // reverseLinkedList(head,curr,prev,forward);
    // cout<<head<<endl;

//     printLink(head);

//    int count= midLinkedList(head);
    // Node* prev=NULL;

    // Node* forward=head->next;
    // Node* curr=head;
    // cout<<count<<endl;

    // head=midLinkedListGroups(head,3);
    // printLink(head);

    // bool ans= checkCircular(head);



    // cout<<"the linked list is circular or note"<<ans<<endl;

    // createLoop(head,tail);
    // bool l=checkLoop(head);
    // cout<<"we are detecting a loop \n";
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