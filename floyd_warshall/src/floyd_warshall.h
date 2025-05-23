#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <queue>
#include <utility>
#include <vector>
#include "graphs.h"
#include <string>

using distance = long long int;
using distances = std::vector<std::vector<distance>>;

using steps = int;

using steps_vector = std::vector<int>;

std::vector<std::vector<distance>> floyd_warshall(weighted_graph& g);
std::string print_distances(distances d);

#endif // !DIJKSTRA_H
