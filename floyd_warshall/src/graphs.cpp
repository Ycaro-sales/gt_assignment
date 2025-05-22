#include <limits>
#include <vector>
#include <iostream>
#include "graphs.h"

#define infinity std::numeric_limits<vertex>::max()

// WEIGHTED GRAPHS METHODS

weighted_graph::weighted_graph(int num_vertices)
{
    adjacency_matrix = std::vector<std::vector<vertex>>(num_vertices, std::vector<vertex>(num_vertices, infinity));
    for(int i = 0; i < num_vertices; i++)
        adjacency_matrix[i][i] = 0;
}

int weighted_graph::size()
{
    return adjacency_matrix.size();
}

int weighted_graph::edges()
{
    int e = 0;
    for(auto v : adjacency_matrix)
    {
        e += v.size();
    }
    // handshake theorem
    return e/2;
}

void weighted_graph::addEdge(vertex v, vertex u, weight w)
{
    adjacency_matrix[v][u] = w;
    adjacency_matrix[u][v] = w;
}

void weighted_graph::print_graph()
{
    for(int v = 0; v < adjacency_matrix.size(); v++)
    {
        std::cout << v + 1 << ": ";
        for(int u = 0; u < adjacency_matrix.size(); u++)
        {
            if(adjacency_matrix[v][u] != infinity)
                std::cout << u + 1 << " (" << adjacency_matrix[v][u] << ") | ";
        }
        std::cout << "\n";
    }
}
