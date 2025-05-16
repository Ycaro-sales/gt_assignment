#include <vector>

#ifndef KRUSKAL_H

typedef int vertex;
typedef float weight;

typedef struct {
    vertex v1;
    vertex v2;
} edge;

typedef struct {
    edge e;
    weight w;
} weighted_edge;

class weighted_graph_vector
{
    public:
    weighted_graph_vector(int size);

    std::vector<weighted_edge> edges;

    void addEdge(vertex v, vertex u, weight w);
    int size_edges();
    int size_vertices();
    int graph_weight();
    void print_graph();
    void print_edges();
    bool edge_compare(weighted_edge vu, weighted_edge xy);
};

class union_find
{
    public:
    union_find(int size);

    std::vector<int> parent;
    std::vector<int> rank;

    void make_set(int x);
    int find(int x);
    void unite(int x, int y);
};


#endif
