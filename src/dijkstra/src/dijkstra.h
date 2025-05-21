#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <queue>
#include <utility>
#include <vector>
#include "graphs.h"

using distance = int;
using steps = int;

using source_distance = std::pair<distance, vertex>;
using steps_vector = std::vector<int>;

std::vector<distance> dijkstra(weighted_graph& g, vertex source);
void print_distances(std::vector<distance> distances);

#endif // !DIJKSTRA_H
