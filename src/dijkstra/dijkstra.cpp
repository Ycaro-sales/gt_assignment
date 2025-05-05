#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include "graphs.h"

using distance = int;
using steps = int;

using vertex_distance = std::pair<distance, vertex>;
using steps_vector = std::vector<int>;

std::tuple<std::vector<distance>, std::vector<steps>> dijkstra(weighted_graph& g, vertex source)
{
    std::priority_queue<vertex_distance, std::vector<vertex_distance>, std::greater<vertex_distance>> Q;

    std::vector<distance> dists(g.size(), -1);
    std::vector<steps> prev(g.size(), -1);

    int cnt = 0;

    dists[source] = 0;

    Q.push(vertex_distance(dists[source], source));

    prev[source] = 0;

    while(!Q.empty())
    {
        vertex v = Q.top().first;
        Q.pop();

        for (neighbor n : g.neighbors[v]){
            distance dist_n = dists[v] + n.weight;

            if (dist_n < dists[n.vertex] || dists[n.vertex] == -1){
                dists[n.vertex] = dist_n;
                prev[n.vertex] = v;
                Q.push(vertex_distance(dist_n, n.vertex));
            }
        }

    }

    return {dists, prev};
}

int main(int argc, char** argv)
{
    return 0;
}
