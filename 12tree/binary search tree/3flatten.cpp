Flatten BST To A Sorted List

https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0


void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &arr){
    if(root==NULL){
        return ;
    }

    inorder(root->left,arr);
    arr.push_back(root);
    inorder(root->right, arr);
   
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<TreeNode<int>* > arr;
    inorder(root, arr);

    TreeNode<int>* newroot=arr[0];

    for(int i=0;i<arr.size()-2;i++){
        arr[i]->left=NULL;
        arr[i]->right=arr[i+1];
    }

    int last=arr.size()-1;
    arr[last]->left=NULL;
    arr[last]->right=NULL;

    return newroot;



}
