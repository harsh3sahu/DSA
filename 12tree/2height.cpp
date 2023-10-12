class Solution

{

private:
    int sum(Node *root) 
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        return sum(root->left) + root->data + sum(root->right);
    }
  
public:
    bool isSumTree(Node *root)
    {

        if (root == NULL)
        {
            return true;
        }

        int sumLeft = sum(root->left);
        int sumRight = sum(root->right);

        bool ans = (sumLeft + sumRight) == root->data;

        return ans && isSumTree(root->left) && isSumTree(root->right);
    }
};







2 
int sum(Node* root){
        
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        
        return sum(root->left) + root->data + sum(root->right);
        
        
        
        
    }
    
    
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL){
             return true;
         }
         
         int sumLeft=sum(root->left);
         int sumRight=sum(root->right);
         
         bool ans= (sumLeft+sumRight)==root->data;
         
        return ans && isSumTree(root->left) && isSumTree(root->right);
         
    }



