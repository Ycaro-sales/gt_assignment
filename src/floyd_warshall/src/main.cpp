#include <fstream>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "graphs.h"
#include "floyd_warshall.h"

using namespace std;

void show_help()
{
    cout << "Usage: ./dijkstra.bin -f <input_file> [OPTIONS]\n\n";
    cout << "Options            Description\n";
    cout << "-h                 Shows this help.\n";
    cout << "-f <input_file>    Reads graph from <input_file>\n";
    cout << "-o <output_file>   Redirects output to <output_file>. Default is standard output.\n";
    cout << "-i <vertex>        Defines initial vertex as <vertex>. Default iniial vertex is 1";
}

int main(int argc, char* argv[])
{
    int help = 0, v0 = 1, opterr = 0, c;
    char *input_file = NULL, *output_file = NULL; 

    while ((c = getopt(argc, argv, "ho:f:i:")) != -1)
    {
        switch (c)
        {
            case 'h':
                help = 1; break;
            case 'o':
                output_file = optarg; break;
            case 'f':
                input_file = optarg; break;
            case 'i':
                v0 = atoi(optarg); break;
        }
    }

    if (help == 1) {
        show_help();
        return 0;
    }
    
    ifstream input(input_file);
    int n, m;
    input >> n >> m;

    weighted_graph g(n);

    int v, u;
    float w;
    for (int i = 0; i < m; i++) {
        input >> v >> u >> w;
        g.addEdge(v-1, u-1, w);
    }

    input.close();

    auto distances = floyd_warshall(g);
    std::string distances_str = print_distances(distances);

    if (output_file != NULL){
        ofstream output(output_file);
        if (output.is_open()){
            output << distances_str;
            output.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
            return 1;
        }
    }

    return 0;
}
