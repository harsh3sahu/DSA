// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;


class graph{

    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v , bool direction){

        adj[u].push_back(v);
        if(direction==false){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){

        for (auto const& [key, value] : adj) {
    // Print the key and value
    std::cout << "Key: " << key << ", Value: ";
    for (auto const& element : value) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }

    }



};

int main(){

    int n;
    cout<<"enter the number of nodes\n";
    cin>>n;


    int e;
    cout<<"enter number of edges\n";
    cin>>e;


    graph g;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    return 0;
}