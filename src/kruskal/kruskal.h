#include <vector>

#ifndef KRUSKAL_H

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
