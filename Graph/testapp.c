//
// Created by Karthik Marri on 02/06/21.
// A test file used to test working of all topologies
//

#include "graph.h"
#include "stdio.h"

extern graph * fourth_topology();

int main()
{
    graph *g=fourth_topology();
    display_graph(g);
    return 0;
}