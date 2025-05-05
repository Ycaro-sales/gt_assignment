#include <vector>
#include <utility>

#ifndef GRAPH_H


typedef int vertex;
typedef float weight;

typedef struct {
    vertex vertex; 
    weight weight;
} neighbor;


class graph
{
    public:
    graph(int num_vertices);

    std::vector<std::vector<int>> adj;

    void addNeighbor(vertex v, vertex neighbor);
    int size();
    int edges();


};

class weighted_graph
{
    public:
    std::vector<std::vector<neighbor>> neighbors;
    weighted_graph(int num_vertices);

    void addEdge(vertex v, vertex u, weight w);

    int size();
    int edges();
};




#endif // !GRAPH_H
