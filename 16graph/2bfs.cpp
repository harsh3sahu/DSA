// #include<bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph
{

public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction)
  {

    adj[u].push_back(v);
    if (direction == false)
    {
      adj[v].push_back(u);
    }
  }

  void printAdjList()
  {

    for (auto const &[key, value] : adj)
    {
      // Print the key and value
      std::cout << "Key: " << key << ", Value: ";
      for (auto const &element : value)
      {
        std::cout << element << " ";
      }
      std::cout << std::endl;
    }
  }
};

// void bfs(unordered_map<int, list<int>> &adjList, vector<int> &ans, unordered_map<int, bool> &visited, int node)
// {

//   queue<int> q;
//   q.push(node);
//   visited[node] = true;

//   while (!q.empty())
//   {
//     int frontNode = q.front();
//     q.pop();

//     ans.push_back(frontNode);

//     for (auto i : adjList[frontNode])
//     {
//       if (!visited[i])
//       {
//         q.push(i);
//         visited[i] = true;
//       }
//     }
//   }
// }

int main()
{

  int n;
  cout << "enter the number of nodes\n";
  cin >> n;

  int e;
  cout << "enter number of edges\n";
  cin >> e;

  graph g;

  // for (int i = 0; i < e; i++)
  // {
  //   int u, v;
  //   cin >> u >> v;
  //   g.addEdge(u, v, 0);
  // }

  vector<int> ans;
  unordered_map<int, bool> visited;

    

  

  return 0;
}