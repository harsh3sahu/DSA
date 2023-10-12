 vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           Node* frontnode=q.front();
           q.pop();
           
           ans.push_back(frontnode->data);
           
           if(frontnode->right){
               q.push(frontnode->right);
           }
          
           else if(frontnode->left) {
               q.push(frontnode->left);
           }
       }
       return ans;
    }