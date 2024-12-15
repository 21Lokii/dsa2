#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Graph {
int V;
vector<pair<int, int>>* adj;

public:
Graph(int V) {
this->V = V;
adj = new vector<pair<int, int>>[V];
}

void addEdge(int u, int v, int w) {
adj[u].push_back(make_pair(v, w));
adj[v].push_back(make_pair(u, w));
}

void dijkstra(int src) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(V, INT_MAX);
pq.push(make_pair(0, src));
dist[src] = 0;

while (!pq.empty()) {
int u = pq.top().second;
pq.pop();

for (auto x : adj[u]) {
int v = x.first;
int weight = x.second;

if (dist[v] > dist[u] + weight) {
dist[v] = dist[u] + weight;
pq.push(make_pair(dist[v], v));
}
}
}

cout << "Vertex Distance from Source" << endl;
for (int i = 0; i < V; ++i)
cout << i << "\t\t" << dist[i] << endl;
}
};

int main() {
Graph g(5);

g.addEdge(0, 1, 2);
g.addEdge(0, 2, 4);
g.addEdge(1, 2, 1);
g.addEdge(1, 3, 7);
g.addEdge(2, 3, 3);
g.addEdge(2, 4, 5);
g.addEdge(3, 4, 1);

g.dijkstra(0);

return 0;
}
