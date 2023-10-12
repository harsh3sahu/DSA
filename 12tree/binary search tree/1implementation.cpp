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

  Node* insertintobst(Node* root, int data){
        if(root==NULL){
            root=new Node(data);
            return root;
        }

        if(data<root->data){
            root->left=insertintobst(root->left,data);

        }
        else{
            root->right=insertintobst(root->right,data);
        }
        return root;
    }

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertintobst(root,data);
        cin>>data;
    }
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<front->data<<"  ";

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }


    }
}

int minValue(Node* root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

Node* deleteFromBST(Node* root, int data){
    if(root==NULL){
        return root;
    }


    if(root->data==data){

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            int mini=minValue(root);
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }


    }

    if(data<root->data){
        root->left=deleteFromBST(root->left,data);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,data);
        return root;
    }
}


int main(){


    Node* root=NULL;
    cout<<"enter data to create bst\n";
    takeInput(root);

    levelOrderTraversal(root);



    return 0;
}