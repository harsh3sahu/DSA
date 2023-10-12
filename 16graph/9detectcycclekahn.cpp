#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int,list<int>> adjList;
    vector<int>indeg(n,0);
    for(int i=0;i<edges.size();i++){
      int u=edges[i].first-1;
      int v=edges[i].second-1;

      adjList[u].push_back(v);
      indeg[v]++;
    }

    vector<int> ans;

    queue<int>q;

  for(int i=0;i<indeg.size();i++){
    if(indeg[i]==0){
      q.push(i);
    }
  }  

  int cnt=0;
  
  while(!q.empty()){
    int frontNode=q.front();
    q.pop();
    ans.push_back(frontNode);

    cnt++;
    
    for(auto neighbour:adjList[frontNode]){
      indeg[neighbour]--;
      if(indeg[neighbour]==0){
        q.push(neighbour);
      }
    }
    
  }

  if(cnt==n){
    return false;
  }
  else
      return true;
}