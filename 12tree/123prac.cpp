#include <iostream>
#include<queue>

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

Node *insertBST(int data, Node *root)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left= insertBST(data, root->left);
    }

    else
    {
        root->right= insertBST(data, root->right);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data = 0;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertBST(data, root);
        }
    }

    
}

void deleteFromtBST(Node*root, int data){

    if(root->data==data){
        
    }





}

void levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        

        for (int i = 0; i < size; i++)
        {

            Node *front = q.front();
            cout<<front->data<<"  ";
            q.pop();

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        cout<<endl;


    }
}

int main()
{

    Node *root=NULL;

    takeInput(root);
    levelOrderTraversal(root);

    return 0;
}