#include <stdio.h>
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

    // cout << "-h " << help << " -o " << output_file << " -f " << input_file << " -i " << v0 << "\n";

    if (help == 1) {
        show_help();
        return 0;
    }
    
    // if (input_file == NULL) { // read graph from stdin
    //     int n, m;
    //     cin >> n >> m;
    //
    //     weighted_graph g(n);
    //
    //     int v, u, w;
    //     for (int i = 0; i < m; i++) {
    //         cin >> v >> u >> w;
    //         g.addEdge(v-1, u-1, w);
    //     }
    // }

    FILE *input = fopen(input_file, "r");

    int n, m;
    fscanf(input, "%d%d", &n, &m);

    weighted_graph g(n);

    int v, u;
    float w;
    for (int i = 0; i < m; i++) {
        fscanf(input,"%d%d%f", &v, &u, &w);
        g.addEdge(v-1, u-1, w);
    }

    fclose(input);

    // g.print_graph();
    auto [costs,prev] = prim(g, v0);

    if(solution == true){
        print_tree(prev);
    } else {
        print_total_cost(costs);
    }

    return 0;
}
