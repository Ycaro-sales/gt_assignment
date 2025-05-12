#include <queue>
#include <utility>
#include <vector>
#include "../graphs.h"

using distance = int;
using steps = int;

using vertex_distance = std::pair<distance, vertex>;
using steps_vector = std::vector<int>;

std::tuple<std::vector<distance>, std::vector<steps>> dijkstra(weighted_graph& g, vertex source);
