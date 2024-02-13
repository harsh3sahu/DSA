
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.

    pair<bool,int> isBalancedFast(Node* root){

        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left=isBalancedFast(root->left);
        pair<bool,int> right=isBalancedFast(root->right);
        
        bool diff= abs(left.second-right.second)<=1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        
        if(left.first && right.first && diff){
            ans.first=true;
        }
        
        else{
            ans.first=false;
        }
        return ans;
        
        
        
        
    }
    
    
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        
        return isBalancedFast(root).first;
    }
};





https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1