#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root,int data){

    if(root==NULL){
        root=new Node(data);
        return root;
    }    

    if(data>root->data){
        root->right=buildTree(root->right, data);
    }

    else{
        root->left=buildTree(root->left,data);
    }

    return root;

}
void takeInput(Node* &root){

    int data;
    cin>>data;


    while(data!=-1){
        root=buildTree(root,data);
        cin>>data;
    }
    
}
Node* minValue(Node *root){
    if(root->left ==NULL ){
        return root;

    }

    return minValue(root->right);
}

Node* deleteNode(Node* root,int x){

    if(root->data==x){

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;

        }

        if(root->left==NULL && root->right!=NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            int mini=(minValue(root->right))->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }        

        
    }

    else if(root->data>x){
        root->left=deleteNode(root->left,x);
        return root;
    } 

    else{
        root->right=deleteNode(root->right,x);
        return root;
    }

    return NULL;

}
// 50 20 70 10 30 90 100 -1
void levelOrder(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout<<"check point\n";


    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<"  ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}
int main(){


    Node* root=NULL;

    cout<<"data to build tree\n";
    takeInput(root);
     
    levelOrder(root);
    // int data;
    // cout<<endl<<"enter node to delete\n";
    // cin>>data;

    // deleteNode(root,data);
    // levelOrder(root);




    return 0;
}