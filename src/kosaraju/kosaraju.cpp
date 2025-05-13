/*
 * 1. DFS pos-ordem no Grafo Reverso
 * 2. ordenar o pos-ordem resultante do DFS do maior pro menor
 * 3. Percorrer o Grafo Original na ordem do pos-ordem
*/

#include <vector>
#include "../graphs.h"
#include <iostream>

using namespace std;

void DFSrec_reverse(directed_graph g, vector<int> &visited, 
            vector<int> &pos, int v)
{
    visited[v] = 1;
    for(auto w : g.in_vector[v])
    {
        if (visited[w] == 0)
        {
            DFSrec_reverse(g, visited, pos, w);
        }
    }
    pos.push_back(v);
}

vector<int> DFS_reverse(directed_graph g)
{
    vector<int> visited(g.size(), 0);
    vector<int> pos;

    for(int v = 0; v < g.size(); v++)
    {
        if(visited[v] == 0)
        {
            DFSrec_reverse(g, visited, pos, v);
        }
    }
    return pos;
}

void DFSrec_scc(directed_graph g, vector<int> &visited, int vertex)
{
    visited[vertex] = 1;
    cout << vertex + 1;
    for(auto neighbour : g.out_vector[vertex])
    {
        if (visited[neighbour] == 0) {
            cout << " ";
            DFSrec_scc(g, visited, neighbour);
        }
    }
}

void DFS_scc(directed_graph g, vector<int> order)
{
    vector<int> visited(g.size(), 0);

    for(int v = (order.size() - 1); v >= 0; v--)
    {
        if(visited[order[v]] == 0)
        {
            DFSrec_scc(g, visited, order[v]);
            cout << endl;
        }
    }
}
