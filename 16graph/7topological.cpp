#include <bits/stdc++.h> 

void solve(unordered_map<int,list<int>>adjList, vector<bool> &visited, stack<int>&s, int n){
  
  visited[n]=true;
  

  for(auto i:adjList[n]){
    if(!visited[i]){
      solve(adjList,visited,s,i);
      }
    
    
  }


    s.push(n);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adjList;
    
    for(int i=0;i<edges.size();i++){
      int x=edges[i][0];
      int u=edges[i][1];
      
      adjList[x].push_back(u);  
    }
    
    vector<bool> visited(v,0);
    
    vector<int> ans;
    stack<int>s;
    
    for(int i=0;i<v;i++){
      if(!visited[i]){
        solve(adjList,visited,s,i);
      }
    
    }

    while(!s.empty()){
      ans.push_back(s.top());
      s.pop();
    }
    
    return ans;
    
}