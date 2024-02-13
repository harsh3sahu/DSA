#include<iostream>
#include<stack>
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

void levelordertraversal(Node *root){
    

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{

        Node* element=q.front();
        q.pop();
        cout<<element->data<<"  ";

        if(element->left){
            q.push(element->left);
        }

        if(element->right){
            q.push(element->right);
        }
        }


    }



}


Node *buildTree(Node *root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root=new Node(data);

    cout<<"enter left element of   "<<root->data<<endl;
    root->left=buildTree(root->left);

    cout<<"enter right element of   "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;

}

void inorderTraversal(Node *root){
    if(root==NULL){
        return ;
    }

    inorderTraversal(root->left);
    cout<<root->data<<endl;
    inorderTraversal(root->right);


}





int main(){


    Node *root=NULL;

    root=buildTree(root);

    // levelordertraversal(root);

    inorderTraversal(root);

    

    return 0;
}