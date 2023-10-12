Sum of nodes on the longest path from root to leaf node
Medium

class Solution
{
    
private:
    void solve(Node *root, int sum ,int len, int &maxSum, int &maxLen){
        
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }
            
            else if(len==maxLen){
                maxSum=max(sum, maxSum);
            }
            
            return;
        }
        
        sum=sum+root->data;
        
        solve(root->left,sum,len+1,maxSum,maxLen);
        solve(root->right,sum, len+1,maxSum, maxLen);
       
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
       int sum=0;
       int maxSum=INT_MIN;
       int len=0;
       int maxLen=0;
       
       solve(root,sum,len,maxSum,maxLen);
       
       return maxSum;
    }
};