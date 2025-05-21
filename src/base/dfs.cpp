#include <vector>
#include "graphs.h"

using namespace std;

void graph::DFSrec(vector<int>& pre, int v)
{
    int cnt = 0;
    pre[v] = cnt++;
    for (int w : adj[v])
    {
        if(pre[w] == -1)
            DFSrec(pre,w);
    }
}

void graph::DFS()
{
    vector<int> pre(size(), -1);
    int cnt = 0;
    int n = size();


    for (int v=0; v<n; v++) 
        pre[v] = -1;

    for (int v=0; v<n; v++) {
        if (pre[v] == -1)
            DFSrec(pre, v);
    }
}
