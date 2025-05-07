#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
    int help = 0, v0 = -1, opterr = 0, c;
    char *input_file = NULL, *output_file = NULL; 

    while ((c = getopt(argc, argv, "ho:f:i:")) != -1) {
        switch (c) {
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

    cout << "-h " << help << " -o " << output_file << " -f " << input_file << " -i " << v0 << "\n";
}
