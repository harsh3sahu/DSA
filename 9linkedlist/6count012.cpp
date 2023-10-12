#include <iostream>
#include<vector>
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

void insertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data);
    temp->next = head;

    head = temp;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

Node *sort012(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    int n=0;
    for (int i = 0; i < 3; i++)
    {

        cout<<"check point "<<n++<<endl;

        while (curr != NULL)
        {
            cout<<"check point **"<<n++<<endl;

            if (curr->data == i)
            {
                if (prev == NULL)
                {
                    head = curr;
                     prev=head;
                }

                else
                {
                    prev->next = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    head = head->next;
                    
                }
               
                curr = prev->next;
                


            }
            else
            {
                prev=curr;
                curr = curr->next;
              
            }
        }


        curr=head->next;
        prev=head;
    }
    return head;
}

Node* sort012(Node* head){
    Node* temp=head;
    Node*forward=head->next;
    Node* prev=NULL;
    Node* head2=head;


    while(head2->data!=0){
        head2=head2->next;
    }

    for(int i=0;i<3;i++){

    }

}


// bool checkPalindrome(Node* head){
//     vector<int>temp;

//     while(head!=NULL){
//         temp.push_back(head->data);
//         head=head->next;
//     }

//     int s=0;
//     int e = temp.size()-1;

//     while(s<=e){
//         if(temp[s]==temp[e]){
//             s++;
//             e--;
//         }

//         else{
//             return false;
//         }
//     }

//     return true;
// }


bool checkPalindrome(Node* head){
    cout<<"printing head  "<<head<<endl;
    // cout<<"printing fast  "<<fast<<endl;
    Node* fast=head;
    cout<<"printing fast  "<<fast<<endl;

    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"printing slow\n";
    printLinkedList(slow);

   

    Node* curr=slow;
    Node* forward=curr->next;
    Node* prev=NULL;
    int n=0;
    while(curr!=NULL ){

        if(forward!=NULL){
        curr->next=prev;
        prev=curr;
        curr=forward;
        forward=forward->next;
        }

        else{
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

    }
    cout<<"printing the reversed linked list\n";
    printLinkedList(prev);
    while(prev!=NULL){
        if(head->data==prev->data){
            head=head->next;
            prev=prev->next;
        }
        else{
            return false;
        }
    }

    return true;

    
}



int main()
{

    Node *head = new Node(0);
    insertAtHead(1, head);
    insertAtHead(1, head);
    insertAtHead(0, head);
    insertAtHead(0, head);
   



    printLinkedList(head);
    cout<<"printing head in main  "<< head<<endl;  
    bool ans=checkPalindrome(head);

    cout<<"after checking\n"<<ans<<endl;
  

    return 0;
}