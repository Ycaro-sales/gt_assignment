#include <fstream>
#include <iostream>
#include <unistd.h>
#include "graphs.h"
#include "prim.h"

using namespace std;

void show_help()
{
    cout << "Usage: ./dijkstra.bin -f <input_file> [OPTIONS]\n\n";
    cout << "Options            Description\n";
    cout << "-h                 Shows this help.\n";
    // cout << "-f <input_file>    Reads graph from <input_file>\n";
    cout << "-o <output_file>   Redirects output to <output_file>. Default is standard output.\n";
    cout << "-i <vertex>        Defines initial vertex as <vertex>. Default iniial vertex is 1";
    cout << "-s                 Shows solution";
}

int main(int argc, char* argv[])
{
    int solution = 0, help = 0, v0 = 1, opterr = 0, c;
    char *input_file = NULL, *output_file = NULL; 

    while ((c = getopt(argc, argv, "ho:f:i:s")) != -1)
    {
        switch (c)
        {
            case 'h':
                help = 1; break;
            case 's':
                solution = 1; break;
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

    // g.print_graph();
    auto [costs,prev] = prim(g, v0);

    std::string output_str;
    if(solution == true){
        output_str = print_tree(prev);
    } else {
        output_str = print_total_cost(costs);
    }

    if (output_file != NULL){
        ofstream output(output_file);
        if (output.is_open()){
            output << output_str;
            output.close();
        } else {
            std::cerr << "Unable to open file for writing." << std::endl;
            return 1;
        }
    } else {
        cout << output_str;
    }

    return 0;
}
