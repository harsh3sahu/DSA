#include <bits/stdc++.h> 

void solve(unordered_map<int,list<int>> &adjList, vector<int>&ans, vector<int> &indeg){

  queue<int>q;

  for(int i=0;i<indeg.size();i++){
    if(indeg[i]==0){
      q.push(i);
    }
  }  
  
  while(!q.empty()){
    int frontNode=q.front();
    q.pop();
    ans.push_back(frontNode);
    
    for(auto neighbour:adjList[frontNode]){
      indeg[neighbour]--;
      if(indeg[neighbour]==0){
        q.push(neighbour);
      }
    }
    
  }


  
}



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adjList;
    vector<int>indeg(v,0);
    for(int i=0;i<e;i++){
      int u=edges[i][0];
      int v=edges[i][1];

      adjList[u].push_back(v);
      indeg[v]++;
    }

    vector<int> ans;
    
  
        solve(adjList,ans,indeg);
     
    
    return ans;


    
}