#include <vector>
#include <utility>

#ifndef GRAPH_H
#define GRAPH_H

using vertex = long long int;
using weight = long long int;

class weighted_graph
{
    public:
    weighted_graph(int num_vertices);

    std::vector<std::vector<vertex>> adjacency_matrix;

    void addEdge(vertex v, vertex u, weight w);
    void addArc(vertex out, vertex in, weight w);
    int size();
    int edges();
    void print_graph();
};

class directed_graph
{
    public:
    directed_graph(int num_vertex);

    std::vector<std::vector<vertex>> in_vector;
    std::vector<std::vector<vertex>> out_vector;

    void addArc(vertex v, vertex u);
    int size();
    int arcs();
    void print_graph();
};

#endif // !GRAPH_H
