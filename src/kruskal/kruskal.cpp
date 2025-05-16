#include "kruskal.h"
#include <algorithm>
#include <iostream>

// UNION-FIND METHODS

 union_find::union_find(int size)
{
    parent.resize(size);
    rank.resize(size);
}

void union_find::make_set(int x)
{
    parent[x] = x;
    rank[x] = 0;
}

int union_find::find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = union_find::find(parent[x]);
    }
    return x;
}

void union_find::unite(int x, int y)
{
    if (rank[x] >= rank[y])
    {
        parent[y] = x;
        if (rank[x] == rank[y])
        {
            rank[x]++;
        }
    }
    else
    {
        parent[x] = y;
    }
}

// WEIGHTED GRAPH VECTOR METHODS

weighted_graph_vector::weighted_graph_vector(int n_vertices, int m_edges)
{
    vertices = n_vertices;
    edges.resize(m_edges);
}

void weighted_graph_vector::addEdge(vertex v, vertex u, weight w)
{
    weighted_edge we;
    we.v1 = v;
    we.v2 = u;
    we.edge_weight = w;
    edges.push_back(we);
}

int weighted_graph_vector::size_edges()
{
    return edges.size();
}

int weighted_graph_vector::graph_weight()
{
    int total_weight = 0;
    for (weighted_edge we : edges)
    {
        total_weight = total_weight + we.edge_weight;
    }
    return total_weight;
}

void weighted_graph_vector::print_graph()
{
    for(weighted_edge we : edges)
    {
        std::cout << "(" << we.v1 << "," << we.v2 << ") " << we.edge_weight << " ";
    }
    std::cout << std::endl;
}

void weighted_graph_vector::print_edges()
{
    for(weighted_edge we : edges)
    {
        std::cout << "(" << we.v1 << "," << we.v2 << ") ";
    }
    std::cout << std::endl;
}

bool edge_compare(weighted_edge const& we1, weighted_edge const& we2)
{
    return we1.edge_weight < we2.edge_weight;
}

// KRUSKAL

weighted_graph_vector kruskal(weighted_graph_vector g)
{
    // creates MST
    weighted_graph_vector MST(g.vertices, g.vertices-1);
    
    // creates UNION-FIND
    union_find un(g.vertices);

    for (int v = 0; v < g.vertices; v++)
    {
        un.make_set(v);
    }

    std::sort(g.edges.begin(), g.edges.end(), &edge_compare);

    g.print_graph();

    for (weighted_edge we : g.edges)
    {
        if (un.find(we.v1) != un.find(we.v2))
        {
            MST.addEdge(we.v1, we.v2, we.edge_weight);
            un.unite(we.v1, we.v2);
        }
    }

    MST.print_edges();
    return MST;
}
