#include <vector>
#include <utility>

#ifndef GRAPH_H
#define GRAPH_H

typedef int vertex;
typedef float weight;

typedef struct {
    vertex v; 
    weight w;
} neighbor;

class graph
{
    public:
    graph(int num_vertices);

    std::vector<std::vector<int>> adj;

    void addNeighbor(vertex v, vertex neighbor);
    int size();
    int edges();

    void DFS();
    void DFSrec(std::vector<vertex>& pre, vertex v);

};

class weighted_graph
{
    public:
    weighted_graph(int num_vertices);

    std::vector<std::vector<neighbor>> adjacency_vector;

    void addEdge(vertex v, vertex u, weight w);
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
