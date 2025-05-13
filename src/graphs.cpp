#include <vector>
#include <tuple>
#include <utility>
#include <iostream>
#include "graphs.h"
#include <queue>

using namespace std;

graph::graph(int num_vertices)
{
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

// WEIGHTED GRAPHS METHODS

weighted_graph::weighted_graph(int num_vertices)
{
    adjacency_vector = vector<vector<pair<int, float>>> (num_vertices, vector<pair<int, float>>());
}

int weighted_graph::size()
{
    return adjacency_vector.size();
}

int weighted_graph::edges()
{
    int e = 0;
    for(auto v : adjacency_vector)
    {
        e += v.size();
    }
    // handshake theorem
    return e/2;
}

void weighted_graph::addEdge(vertex v, vertex u, weight w)
{
    adjacency_vector[v].push_back({u, w});
    adjacency_vector[u].push_back({v, w});
}

void weighted_graph::print_graph()
{
    for(int v = 0; v < adjacency_vector.size(); v++)
    {
        cout << v + 1 << ": ";
        for(auto neighbor : adjacency_vector[v])
        {
            cout << neighbor.first + 1 << " (" << neighbor.second << ") | ";
        }
        cout << "\n";
    }
}

// DIRECTED GRAPH METHODS

directed_graph::directed_graph(int num_vertex)
{
    in_vector = vector<vector<int>> (num_vertex, vector<int>());
}

void directed_graph::addArc(vertex v, vertex u)
{
    out_vector[v].push_back(u);
    in_vector[u].push_back(v);
}

int directed_graph::size()
{
    return out_vector.size();
}

int directed_graph::arcs()
{
    int a = 0;
    for(auto v : out_vector)
    {
        a += v.size();
    }
    return a;
}

void directed_graph::print_graph()
{
    for(int v = 0; v < out_vector.size(); v++)
    {
        cout << v + 1 << ": ";
        for(auto neighbor : out_vector[v])
        {
            cout << neighbor << " | ";
        }
        cout << "\n";
    }
}
