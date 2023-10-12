#include<bits/stdc++.h>

void dfs(unordered_map<int,list<int>> &adjList,int &node,int &parent, int &timer,vector<int>&discovery,vector<int>&low, vector<vector<int>>&result, vector<bool> &visited)
{

    visited[node]=true;
    discovery[node]=low[node]=timer++;

    for(auto nbr:adjList[node]){
        if(nbr==parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(adjList,nbr,node,timer,discovery,low,result,visited);
            low[node]=min(low[node],low[nbr]);
        //check if edge is bridge
            if(low[nbr]>discovery[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }

        else{
            //back edge
            low[node]=min(low[node],discovery[nbr]);
        }
    }


}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int timer=0;

    vector<int> discover(v,-1);
    vector<int> low(v,-1);
    vector<bool>visited(v);
    int parent=-1;
    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adjList,i,parent,timer,discover,low,result,visited);
        }
    }


    return result;




}