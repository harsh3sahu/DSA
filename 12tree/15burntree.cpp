
    Node *createMapping(Node *root, int target, map<Node*,Node*> &nodeParent){
        
        Node *res=NULL;
        nodeParent[root]=NULL;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node *front=q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
                
            }
            
            if(front->left){
                nodeParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeParent[front->right]=front;
                q.push(front->right);
            }
        }
        
        return res;
        
        
    }
    
    int burnTree(Node* root,map<Node*,Node*> &nodeParent){
        
        map<Node *, bool> visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        
        int ans=-1;
        bool flag=0;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *front=q.front();
                q.pop();
                
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=1;
                    flag=1;
                     
                }
                
                 if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=1;
                    flag=1;
                     
                }
                
                if(nodeParent[front] && !visited[nodeParent[front]]){
                    q.push(nodeParent[front]);
                    visited[nodeParent[front]]=1;
                    flag=1;
                }
                
            }
            
            if(flag==1){
                ans++;
            }
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        map<Node *,Node*> nodeParent;
        Node* targetNode=createMapping(root,target,nodeParent);
        
       int ans= burnTree(targetNode, nodeParent);
       if(ans==-1){
           return 0;
       }
       else
             return ans; 
    }
};



abhi vaala 


class Solution {
    private:
    Node* createMapping(Node* root,int target,map<Node*,Node*> &parent){
        
        Node* targetNode=NULL;
        
        parent[root]=NULL;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
                targetNode=front;
            }
            
            if(front->left){
                q.push(front->left);
                parent[front->left]=front;
            }
            
            if(front->right){
                q.push(front->right);
                parent[front->right]=front;
            }
            
        }
        
        return targetNode;
        
        
        
    }
    
    int solve( Node* root, map<Node*,Node*> &parent){
        
        map<Node*,bool> burn;
        queue<Node*>q;
        q.push(root);
        burn[root]=true;
        int ans=-1;
        int flag=0;

        
        while(!q.empty()){
            
            int size=q.size();

            
            
            for(int i=0;i<size;i++){
            Node* front=q.front();
            q.pop();

            
            if(front->left && !burn[front->left]){
                q.push(front->left);
                burn[front->left]=true;
                flag=1;
            }
            
            if(front->right && !burn[front->right]){
                q.push(front->right);
                burn[front->right]=true;
                flag=1;
            }
            
            if(parent[front] && !burn[parent[front]]){
                q.push(parent[front]);
                burn[parent[front]]=true;
                flag=1;
            }
            
            
            
            }
            
            if(flag==1){
                ans++;
            }
            
            
        }
        
        return ans;
        
        
        
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>parent;
        
        Node* targetNode=createMapping(root,target,parent);
        
        int ans=solve(targetNode,parent);
        
        if(ans==-1){
            return 0;
        }
        return ans;

    }
};