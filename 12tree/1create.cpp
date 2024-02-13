#include <iostream>
#include <queue>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildtree(Node *root)
{

    int data;
    cout << "enter data\n";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "enter data to the left of " << data << endl;
    root->left=buildtree(root->left);

    cout << "enter data to the right of " << data << endl;
    root->right=buildtree(root->right);
    return root;
}

void levelordertraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data<<"  ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inordertraversal(Node *root){

    if(root==NULL){
        return ;
    }

    inordertraversal(root->left);

    cout<<root->data<<" ";

    inordertraversal(root->right);

    return ;

}

void preordertraversal(Node *root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";

    preordertraversal(root->left);
    preordertraversal(root->right);

    return ;

}

void postorder(Node *root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

    return ;
}

void treefromlevel(Node* &root){

    queue<Node*> q;
    int data;

    cout<<"enter data for root"<<endl;
    cin>>data;

    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();


        cout<<"enter data for left of "<<temp->data<<endl;
        int left;
        cin>>left;

        if(left!=-1){
            temp->left=new Node(left);
            q.push(temp->left);
        }

        cout<<"enter data for right of "<< temp->data<<endl;
        int right;
        cin>>right;

        if(right!=-1){
            temp->right=new Node(right);
            q.push(temp->right);
        }


    }



}

int main()
{

    // Node *root = NULL;

    // root =buildtree(root);

    // levelordertraversal(root);

    // inordertraversal(root);

    // preordertraversal(root);

    // postorder(root);

    Node* tree2;
    treefromlevel(tree2);

    levelordertraversal(tree2);

    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1