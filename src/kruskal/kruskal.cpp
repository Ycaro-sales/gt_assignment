#include "kruskal.h"
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

weighted_graph_vector::weighted_graph_vector(int size)
{
    edges.resize(size);
}

void weighted_graph_vector::addEdge(vertex v, vertex u, weight w)
{
    edge e;
    e.v1 = v;
    e.v2 = u;
    weighted_edge we;
    we.e = e;
    we.w = w;
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
        total_weight = total_weight + we.w;
    }
    return total_weight;
}

void weighted_graph_vector::print_graph()
{
    for(weighted_edge we : edges)
    {
        std::cout << "(" << we.e.v1 << "," << we.e.v2 << ") " << we.w << " ";
    }
    std::cout << std::endl;
}

void weighted_graph_vector::print_edges()
{
    for(weighted_edge we : edges)
    {
        std::cout << "(" << we.e.v1 << "," << we.e.v2 << ") ";
    }
    std::cout << std::endl;
}

bool weighted_graph_vector::edge_compare(weighted_edge we1, weighted_edge we2)
{
    return we1.w < we2.w;
}
