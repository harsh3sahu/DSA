#include<bits/stdc++.h>


bool solve(unordered_map<int,list<int>> adjList, vector<bool> &visited, vector<bool> dfsVisited, int node){
  
  visited[node]=true;
  dfsVisited[node]=true;

  for(auto neighbour:adjList[node]){
      if(!visited[neighbour]){
        bool cycleDetected=solve(adjList,visited,dfsVisited,neighbour);
          if(cycleDetected){
            return true;
          }       
      }    
      
      else if(dfsVisited[neighbour]){
        return true;
      }
  }

      dfsVisited[node]=false;   
      return false;
  
}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adjList;
  
  for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;

      adjList[v].push_back(u);
      
  } 
    
    vector<bool> visited(n,false);
    vector<bool> dfsVisited(n,false);

    
    for(int i=0;i<n;i++){
      
      if(!visited[i]){
        bool output=solve(adjList,visited,dfsVisited,i);
        if(output==true){
          return 1;
        }
      }
            
    }

    return 0;
      




  
}