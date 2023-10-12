#include <iostream>
using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printL(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->next;
    }

    cout<<endl;
}

Node *removeDuplicates(Node *&head)
{

    Node *curr = head;
    Node *forward = curr->next;
    Node *temp = curr;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (forward != NULL)
    {
        if (curr->data == forward->data)
        {
            curr->next = forward->next;
            // curr = curr->next;
            forward = forward->next;
            // delete(forward);
        }

        else
        {
            curr = curr->next;
            forward = forward->next;
        }
    }
    return temp;
}

Node *removeUnsorted(Node *&head)
{
    Node* head1=head;
    Node *forward = head->next->next;
    Node *temp = head->next;
    

    // cout<<endl<<*head<<endl;
    // cout<<*temp<<endl;
    // cout<<prev->data<<endl;

    while (head->next != NULL)
    {

        while (forward != NULL)
        {
            if (head->data == forward->data)
            {
                temp->next = forward->next;
                forward = forward->next;
                temp=temp->next;
            }
            else{
                // temp=temp->next;
                
                forward=forward->next;
            }
        }

        head=head->next;
        forward=head->next;
        temp=head1;
    }
    return temp;
}

Node* mergeList(Node* &node1, Node* &node2){

    int data;
    Node* head;
    if(node1->data <= node2->data){
        head=node1;
        node1=node1->next;
    }
    else {
        head=node2;
        node2=node2->next;
    }

    Node* ans = head;
    while(node1!=NULL && node2!= NULL ){

        cout<<"merging\n";
        if(node1->data <= node2->data){
            head->next=node1;
            head=head->next;;
            node1=node1->next;
        }

        else{
            head->next=node2;
            head=head->next;
            node2=node2->next;

        }
    }

    while(node1!=NULL){
        head->next=node1;
        head=head->next;;
        node1=node1->next;
        cout<<"merging 1\n";

    }

    while(node2!=NULL){
        head->next=node2;
        head=head->next;;
        node2=node2->next;
        cout<<"merging 2\n";

    }
    // head->next=NULL;

    return ans;

}


int main()
{

    Node *node1 = new Node(50);
    insertAtHead(node1, 40);
    insertAtHead(node1, 30);
    insertAtHead(node1, 25);
    insertAtHead(node1, 15);
    insertAtHead(node1, 1);
    // insertAtHead(node1, 30);
    // insertAtHead(node1, 50);
    // insertAtHead(node1, 60);
    // insertAtHead(node1, 30);

    Node *node2 = new Node(70);
    insertAtHead(node2, 60);
    insertAtHead(node2, 35);
    insertAtHead(node2, 20);
    insertAtHead(node2, 10);





    printL(node1);
    printL(node2);

    
    // Node *head = removeDuplicates(node1);

    // cout << endl << "after removing duplicates\n";

    // printL(head);

    // Node *newhead = removeUnsorted(node1);

    // cout<<"\n after removing it from unsorted list \n";

    // printL(newhead);


    Node* mergehead=mergeList(node1,node2);
    printL(mergehead);

    return 0;
}