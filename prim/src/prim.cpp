#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include "graphs.h"

using cost = int;
using parent = int;

using source_cost = std::pair<cost, vertex>;

// 1:0 2:3 3:4 4:5 5:6 6:7 7:8 8:9 9:10 10:11 11:12 12:13 13:14 14:15 15:16 16:17 17:18 18:19 19:20 20:21 21:22 22:23 23:24 24:25 25:26 26:26 27:25 28:24 29:23 30:22 31:21 32:20 33:19 34:18 35:17 36:16 37:15 38:14 39:13 40:12 41:11 42:10 43:9 44:8 45:7 46:6 47:5 48:4 49:1 50:2 51:2 52:3 53:4 54:5 55:6 56:7 57:8 58:9 59:10 60:11 61:12 62:13 63:14 64:15 65:16 66:17 67:18 68:19 69:20 70:21 71:22 72:23 73:24 74:25 75:26 76:26 77:25 78:24 79:23 80:22 81:21 82:20 83:19 84:18 85:17 86:16 87:15 88:14 89:13 90:12 91:11 92:10 93:9 94:8 95:7 96:6 97:5 98:4 99:1 100:2 101:2 102:3 103:4 104:5 105:6 106:7 107:8 108:9 109:12 110:11 111:12 112:13 113:14 114:15 115:16 116:17 117:18 118:19 119:20 120:21 121:22 122:23 123:24 124:25 125:26 
std::string print_costs(std::vector<cost> costs){
    std::string costs_str = "";
    for(int i = 0; i < costs.size(); i++){
        costs_str += std::to_string(i+1) + ":" + std::to_string(costs[i]) + " ";
    }
    costs_str += "\n";
    return costs_str;
}

std::string print_prev(std::vector<cost> prev){
    std::string prev_str = "";
    for(int i = 0; i < prev.size(); i++){
        prev_str += std::to_string(i+1) + ":" + std::to_string(prev[i]) + " ";
    }
    prev_str += "\n";
    return prev_str;
}

std::string print_tree(std::vector<cost> prev){
    std::string tree_str = "";

    for(int i = 0; i < prev.size(); i++){
        if (i != prev[i]){
            tree_str += "(" + std::to_string(prev[i]+1) + "," + std::to_string(i+1) + ") ";
        }
    }

    tree_str += "\n";

    return tree_str;
}

std::string print_total_cost(std::vector<cost> costs){
    cost sum = 0;
    for(int i = 0; i < costs.size(); i++){
        sum += costs[i];
    }
    return std::to_string(sum);
}

std::tuple<std::vector<cost>, std::vector<parent>>  prim(weighted_graph& g, vertex source)
{
    source -= 1;
    std::priority_queue<source_cost, std::vector<source_cost>, std::greater<source_cost>> Q;

    std::vector<cost> costs(g.size(), -1);
    std::vector<parent> prev(g.size(), -1);
    std::vector<bool> done(g.size(), false);

    int cnt = 0;

    costs[source] = 0;

    Q.push(source_cost(costs[source], source));

    prev[source] = 0;

    while(!Q.empty())
    {
        vertex v = Q.top().second;
        Q.pop();
        done[v] = true;

        for (auto n : g.adjacency_vector[v]){
            if ((costs[n.v] > n.w || costs[n.v] == -1) && done[n.v] == false){
                costs[n.v] = n.w;
                prev[n.v] = v;
                Q.push(source_cost(costs[n.v], n.v));
            }
        }

    }

    return std::make_tuple(costs, prev);
}
