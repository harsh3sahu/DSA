
void inOrderTraversal(BinaryTreeNode<int>* root, vector<int> &ans){
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left,ans);

    ans.push_back(root->data);

    inOrderTraversal(root->right,ans);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorder;
    inOrderTraversal(root,inorder);
    
    int start=0;
    int end=inorder.size()-1;
    

   
    while(start<end){
        if(inorder[start]+inorder[end]==target){
            return true;
        }

        else if(inorder[start]+inorder[end]>target){
            end--;
        }
        else{
            start++;
        }
    }

    
        return false;
    
    
}