#include<queue>
#include<limits.h>

class Node{

    public:
    int data;
    int row;
    int col;
    
    Node(int data,int r, int c){
        this->data=data;
        row=r;
        col=c;
    }
    
};

class compare{
    public:
    
    bool operator()(Node *a,Node* b){
        return a->data>b->data;
    }

    
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<Node*,vector<Node*> ,compare> pq;

    int mini=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<k;i++){
        
        Node* temp=new Node(a[i][0],i,0);
        pq.push(temp);
        mini=min(mini,a[i][0]);
        maxi=max(maxi,a[i][0]);
    }

    int start=mini;
    int end=maxi;
    
    while(!pq.empty()){

        Node *temp=pq.top();
        pq.pop();

        mini=temp->data;
        
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            Node* curr=new Node(a[temp->row][temp->col+1],temp->row,temp->col+1);
            pq.push(curr);
        }
        else{
            break;
        }



        
    }
    


    return end-start+1;
    
}