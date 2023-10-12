#include<queue>
#include<vector>

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

class compare{
    public:
    bool operator()(Node *a, Node* b){
        return a->data>b->data;
    }
    
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto i:listArray){
        pq.push(i);
    }

    

    Node* ans=pq.top();
    pq.pop();
    if(ans->next!=NULL){
        pq.push(ans->next);
    }
    Node* curr=ans;
     
    while(!pq.empty()){

        Node* temp=pq.top();
        pq.pop();
       

        if(temp!=NULL){
             curr->next=temp;
            curr=curr->next;
            if (temp->next != NULL) {
              pq.push(temp->next);
            }
        }
        
      
    }

    return ans;


    
}
