
class Solution {
  public:
  
  int countNodes(struct Node* root){
      if(root==NULL){
          return 0;
      }
      
      
      int ans= 1+ countNodes(root->left) + countNodes(root->right);
      return ans;
  }
  
  
   bool isCBT(struct Node *root,int index, int cnt){
       
       if(root==NULL){
           return true;
       }
       
       if(index>=cnt){
           return false;
       }
       
       
       else{
           bool left=isCBT(root->left, 2*index+1, cnt);
           bool right=isCBT(root->right, 2*index+2, cnt);
           
           return  (left && right);
           
       }
        
    }
    
    bool isMAX( struct Node* root){
        if(root->left ==NULL && root->right ==NULL){
            return true;
            
        }
        
        else if(root->right==NULL){
            return root->data > root->left->data;
        }
        
        else{
            bool left=isMAX(root->left);
            bool right =isMAX(root->right);
            
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
        
    }
    bool isHeap(struct Node* tree) {
        // code here
        
        int index=0;
        int cnt=countNodes(tree);
        
        if(isCBT(tree,index,cnt) && isMAX(tree)){
            
            return true;
            
        }
        
        else{
            return false;
        }
        
        
    }
    
    
   
};