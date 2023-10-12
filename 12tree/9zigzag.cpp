
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	
    	bool left =true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> level(size);
    	    
    	    for(int i=0;i<size;i++){
    	        Node *temp=q.front();
    	        q.pop();
    	        
    	        int index=left?i:size-i-1;
    	        level[index]=temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	        
    	        
    	    }
    	    left=!left;
    	    
    	    
    	    for(auto i:level){
    	        ans.push_back(i);
    	    }
    	    
    	    
    	    
    	}
    	
    	return ans;
    	
    	
    	
    }
};

