

#include<bits/stdc++.h>

void solve(unordered_map<int,list<int>> &adjList,unordered_map<int,bool>&visited,unordered_map<int,int> &parent, int &node){
	
	queue<int> q;
	q.push(node);
	parent[node]=-1;
	
	visited[node]=true;
	
	while(!q.empty()){
		int frontNode=q.front();
		q.pop();
		
		for(auto neighbour:adjList[frontNode]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour]=true;
				parent[neighbour]=frontNode;
			}
		}
	}
	
	
	

	
}



vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adjList;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;
		
		adjList[u].push_back(v);
        adjList[v].push_back(u);
		
	}

	unordered_map<int,bool> visited;
	
		unordered_map<int,int> parent;

	
        
    vector<int> path;
    solve(adjList, visited, parent,s);
               
	

	int curr=t;
	path.push_back(curr);
	while(curr!=s ){
		curr=parent[curr];

		path.push_back(curr);

	}
	reverse (path.begin(),path.end());
		
        return path;
}
