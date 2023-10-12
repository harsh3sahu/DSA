#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {
  // Write your code here.

  unordered_map<int, list<pair<int, int>>> adjList;
  for (int i = 0; i < vec.size(); i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];
    pair<int, int> p = make_pair(v, w);
    adjList[u].push_back(p);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  vector<int> dist(vertices, INT_MAX);

  dist[source] = 0;

  s.push(make_pair(source, 0));

  

  while (!s.empty()) {
    pair<int, int> topElement = s.top();
    s.pop();



    for (auto i : adjList[topElement.first]) {

      int v = i.first;
      int w = i.second;

      if (w + dist[topElement.first] < dist[v]) {
        dist[v] = w + dist[topElement.first];

        s.push(make_pair(v, dist[v]));
      }
    
    }
  }
  return dist;
}
