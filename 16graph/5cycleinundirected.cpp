#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

bool cycle(unordered_map<int,list<int>>&adjList,int node,vector<bool>&visited, unordered_map<int,int> &parent){
    
    queue<int> q;
    q.push(node);
    visited[node]=true;
    
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
        for(auto i:adjList[frontNode]){
            if(visited[i] && parent[frontNode]!=i){
                return true;
            }
            if (!visited[i]) {

                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }

    return false;

    
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adjList;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<bool>visited(n,false);
    unordered_map<int,int>parent;
    for(int i=0;i<n;i++){
        parent[i]=-1;
    }
    for(int i=0;i<n;i++){
       
        if(!visited[i]){
            
            bool output=cycle(adjList,i,visited, parent);
            if(output){
                return "Yes";
            
        }
        }
    }
   return "No";
    
    
}
