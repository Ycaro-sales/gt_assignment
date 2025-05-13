#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "kosaraju.h"

using namespace std;

void show_help()
{
    cout << "Usage: ./kosaraju -f <input_file> [OPTIONS]\n\n";
    cout << "Options            Description\n";
    cout << "-h                 Shows this help.\n";
    cout << "-o <output_file>   Redirects output to <output_file>. Default is standard output.\n";
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

    directed_graph g(n);

    int v, u;
    for (int i = 0; i < m; i++)
    {
        fscanf(input, "%d%d", &v, &u);
        g.addArc(v - 1, u - 1);
    }

    fclose(input);

    vector<int> post_order = DFS_reverse(g);

    DFS_scc(g, post_order);

    return 0;
}
