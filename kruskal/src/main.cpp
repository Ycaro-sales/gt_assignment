#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include "kruskal.h"

void show_help()
{
    std::cout << "Usage: ./kosaraju -f <input_file> [OPTIONS]\n\n";
    std::cout << "Options            Description\n";
    std::cout << "-h                 Shows this help.\n";
    std::cout << "-o <output_file>   Redirects output to <output_file>. Default is standard output.\n";
    std::cout << "-s                 Shows solution.\n";
}

int main(int argc, char *argv[])
{
    int help = 0, solution = 0, opterr = 0, c;
    char *input_file = NULL, *output_file = NULL;

    while((c = getopt(argc, argv, "ho:f:s")) != -1)
    {
        switch(c)
        {
            case 'h':
                help = 1; break;
            case 'o':
                output_file = optarg; break;
            case 'f':
                input_file = optarg; break;
            case 's':
                solution = 1; break;
        }
    }

    if (help == 1)
    {
        show_help();
        return 0;
    }

    std::ifstream input(input_file);
    int n, m;
    input >> n >> m;

    weighted_graph_vector g(n, m);

    int v, u, w;
    for (int i = 0; i < m; i++) {
        input >> v >> u >> w;
        g.addEdge(v-1, u-1, w);
    }

    input.close();

    weighted_graph_vector MST = kruskal(g);

    std::string output_str;

    if (solution == 1) {
        output_str = MST.print_edges();
    } else {
        output_str= std::to_string(MST.graph_weight()) + "\n";
    }

    if (output_file != NULL){
        std::ofstream output(output_file);
        if (output.is_open()){
            output << output_str;
            output.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
            return 1;
        }
    } else {
        std::cout <<  output_str;
    }

    return 0;
}
