#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

class graph{

    public:
    unordered_map<int,list<int>> m;

    void addEdge(int u,int v ,bool direction){
        m[u].push_back(v);
        if(direction==false){
            m[v].push_back(u);
        }

    }
    
};

void bfsTraversal(unordered_map<int,list<int>> m, unordered_map<int,bool> &visited,vector<int> &ans){
    queue<int> q;
    q.push_back(m[0][0]);
    visited[0]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i:m[frontNode]){

            if(!visited){
            q.push(i);
            visited[i]=true;
            }
        }

    }
}


int main(){

    graph g;
    int edges;
    cout<<"enter number of edges\n";
    cin>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        bool dir;
        cin>>u>>v>>dir;
        g.addEdge(u,v,dir);
    }


    vector<int> ans;
    unordered_map<int,bool> visited(edges);

    bfsTraversal(g.m,visited,ans);

    for(auto i:ans){
        cout<<ans<<"  ";
    }


    return 0;
}