#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>
#include <iostream>
#include "graphs.h"
#include <limits>
#include <string>

#define infinity std::numeric_limits<vertex>::max()

using distance = long long int;
using distances = std::vector<std::vector<distance>>;
using steps = int;
using steps_vector = std::vector<int>;

using namespace std::literals;

std::string print_distances(distances d){
    std::string dists_str = "";
    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d.size(); j++) {
            std::string curr_dist = std::to_string(i+1) + ":" +std::to_string(j+1) + ":";
            if (d[i][j] != infinity)
                dists_str += curr_dist + std::to_string(d[i][j]) +  "\t";
            else
                dists_str += curr_dist + "INF\t";
        }
        dists_str += "\n";
    }

    return dists_str;
}

distances floyd_warshall(weighted_graph& g){
    int n = g.size();

    distances d = g.adjacency_matrix;

    print_distances(d);

    std::cout << std::endl;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (d[i][k] != infinity && d[k][j] != infinity)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}


#endif // !DIJKSTRA_H
