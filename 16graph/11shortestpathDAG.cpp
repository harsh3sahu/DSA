#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include<stack>

using namespace std;

void shortestPath(stack<int> &s,unordered_map<int,list<pair<int,int>>> adjList, vector<int> &dist, int src){

    while(s.top()!=src){
        s.pop();
    }
    
    int top=dist[s.top()]=0;
    

    while(!s.empty()){
        for(auto i:adjList[s.top()]){
            if(i.second+dist[s.top()]<dist[i.first]){
                dist[i.first]=dist[s.top()]+i.second;
            }
        }
        s.pop();
    }


}

void topologicalSort(unordered_map<int, list<pair<int, int>>> &adjList, unordered_map<int,bool> &visited, stack<int> &s, int node)
{

    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i.first])
        {
            int p=i.first;
            visited[p]=true;

            topologicalSort(adjList, visited, s, p);
        }
    }

    s.push(node);
}

class graph
{

public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adjList[u].push_back(p);
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j.first << " " << j.second << endl;
            }
        }
    }
};

int main()
{

    graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    unordered_map<int,bool> visited;
    stack<int> s;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited[i])
        {
            topologicalSort(g.adjList, visited, s, i);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    // vector<int> dist(s.size(),INT_MAX);

    // shortestPath(s, g.adjList,dist, 1);

    // for(auto i:dist){
    //     cout<<i<<endl;
    // }



    return 0;
}