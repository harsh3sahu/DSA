vector<int> leftView(Node *root)
{
   // Your code here
      vector<int> ans;

   if(root==NULL){
       return ans;
   }
   
   map<int,int> leftNode;
   
   queue<pair<Node*,int>> q;
   q.push(make_pair(root,0));
   
   while(!q.empty()){
       pair<Node*, int> temp=q.front();
       q.pop();
       
       Node* leftMost=temp.first;
       int hd=temp.second;
       
       if(leftNode.find(hd)==leftNode.end()){
           leftNode[hd]=leftMost->data;
       }
       
       if(leftMost->left){
           q.push(make_pair(leftMost->left,hd-1));
       }
        else if(leftMost->right){
           q.push(make_pair(leftMost->right,hd+1));
       }
       
       
       
       
   }
   
   for(auto i:leftNode){
       ans.push_back(i.second);
   }
   
   return ans;
}