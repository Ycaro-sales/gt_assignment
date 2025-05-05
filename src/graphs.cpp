#include <vector>
#include <tuple>
#include <utility>
#include "graphs.h"
#include <queue>

using namespace std;

graph::graph(int num_vertices){
    adj = vector<vector<int>>(num_vertices, vector<int>());
}

void graph::addNeighbor(int vertex, int neighbor)
{
    adj[vertex].push_back(neighbor);
}

int graph::size()
{
    return adj.size();
}

int graph::edges()
{
    int n = 0;

    for (auto vertex_neighbors : adj)
    {
        n += vertex_neighbors.size();
    }

    // handshake theorem
    return  n/2;
}

weighted_graph::weighted_graph(int num_vertices) {
    neighbors = adjancency_vector(num_vertices, vector<pair<int,float>>());
}

int weighted_graph::size()
{
    return neighbors.size();
}

void weighted_graph::addEdge(vertex v, vertex u, weight w)
{
    neighbors[v].push_back({u, w});
    neighbors[u].push_back({v, w});
}

// float weighted_graph::getEdgeWeight(vertex v, vertex u)
// {
//
// }
