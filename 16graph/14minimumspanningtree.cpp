#include<bits/stdc++.h>
bool cmp(vector<int>&a, vector<int> &b){
  return a[2]<b[2];
}


void makeSet(vector<int> &rank, vector<int>&parent ,int n){
  for(int i=0;i<n;i++){
    rank[i]=0;
    parent[i]=i;
  }
}

int findParent(vector<int> &parent,int node){
  if(parent[node]==node){
    return node;
  }

  return parent[node]= findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u=findParent(parent,u);
  v=findParent(parent,v);

  if(rank[u] < rank[v]){
    parent[u]=v;
  }
  else if(rank[u]>rank[v]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{

    sort(edges.begin(),edges.end(),cmp);
    vector<int> rank(n);
    vector<int> parent(n);

    makeSet(rank,parent,n);
    int minWeight=0;
    for(int i=0;i<edges.size();i++){
      int u=findParent(parent, edges[i][0]);
      int v=findParent(parent, edges[i][1]);
      int w=edges[i][2];

      if(u!=v){
        minWeight=minWeight+w;
        unionSet(u,v,parent,rank);
      }

    }
  return minWeight;

}