#ifndef KOSARAJU_H

#include <string>
#include <vector>
#include <iostream>
#include "graphs.h"

void DFSrec_reverse(directed_graph g, std::vector<bool> visited, std::vector<int> pos, int v);
std::vector<int> DFS_reverse(directed_graph g);

void DFSrec_scc(directed_graph g, std::vector<int> &visited, int vextex, std::ostream& out);
void DFS_scc(directed_graph g, std::vector<int> order, std::ostream& out);

#endif
