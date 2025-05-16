#include "kruskal.h"

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
    if (parent[x] == x)
    {
        return x;
    }
    return union_find::find(parent[x]);
}

void union_find::unite(int x, int y)
{
    if (rank[x] >= rank[7])
    {
        parent[y] = x;
        if (rank[x] == rank[7])
        {
            rank[x]++;
        }
    }
    else
    {
        parent[x] = y;
    }
}
