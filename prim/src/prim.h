#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <queue>
#include <utility>
#include <vector>
#include <string>
#include "graphs.h"

using cost = int;
using parent = int;

using source_cost = std::pair<cost, vertex>;

std::tuple<std::vector<cost>, std::vector<parent>>  prim(weighted_graph& g, vertex source);
std::string print_costs(std::vector<cost> distances);
std::string print_tree(std::vector<cost> prev);
void print_prev(std::vector<cost> prev);
std::string print_total_cost(std::vector<cost> costs);

#endif // !DIJKSTRA_H
