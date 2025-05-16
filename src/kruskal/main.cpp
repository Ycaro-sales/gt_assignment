#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "kruskal.h"

void show_help()
{
    std::cout << "Usage: ./kosaraju -f <input_file> [OPTIONS]\n\n";
    std::cout << "Options            Description\n";
    std::cout << "-h                 Shows this help.\n";
    std::cout << "-o <output_file>   Redirects output to <output_file>. Default is standard output.\n";
}

int main(int argc, char *argv[])
{
    int help = 0, opterr = 0, c;
    char *input_file = NULL, *output_file = NULL;

    while((c = getopt(argc, argv, "ho:f:")) != -1)
    {
        switch(c)
        {
            case 'h':
                help = 1; break;
            case 'o':
                output_file = optarg; break;
            case 'f':
                input_file = optarg; break;
        }
    }

    if (help == 1)
    {
        show_help();
        return 0;
    }

    FILE *input = fopen(input_file, "r");

    int n, m;
    fscanf(input, "%d%d", &n, &m);

    weighted_graph_vector g(n, m);

    int v, u, w;
    for (int i = 0; i < m; i++)
    {
        fscanf(input, "%d%d%d", &v, &u, &w);
        g.addEdge(v, u, w);
    }

    fclose(input);

    weighted_graph_vector MST = kruskal(g);

    return 0;
}
