//
// Created by Karthik Marri on 01/06/21.
//This file contains different topologies
//

#include "stdio.h"
#include "graph.h"
#include "stdlib.h"

graph *first_topology()
{

#if 0

                          +----------+
                   eth0/4 |          |eth0/0
         +----------------+   R1     +---------------------------+
         |                |          |                           |
         |                +----------+                           |
         |                                                       |
         |                                                       |
         |                                                       |
         |                                                       |
         |eth0/5                                                 |eth0/1
     +---+---+                                              +----+-----+
     |       |eth0/3                                  eth0/2|          |
     | R3    +----------------------------------------------+    R2    |
     |       |                                              |          |
     +-------+                                              +----------+

#endif

    graph *topo1=create_graph("first_graph");
    DLL *D1=create_node(topo1,"R1");
    DLL *D2=create_node(topo1,"R2");
    DLL *D3=create_node(topo1,"R3");

    insert_link_between_nodes(D1->N,D2->N,"eth0/0","eth0/1",1);
    insert_link_between_nodes(D2->N,D3->N,"eth0/2","eth0/3",1);
    insert_link_between_nodes(D1->N,D3->N,"eth0/4","eth0/5",1);
    return topo1;
}

graph *second_topology()
{

#if 0
                                       +-----------+
                                       |  R4       |
                                       |           |
                                       +----+------+
                                            |eth0/7
                                            |
                                            |eth0/1
                                       +----+----+                        +--------+
       +---------+                     |         |                        |        |
       |         |                     |   S1    |eth0/2                  |  R3    |
       |  R1     +---------------------+         +------------------------+        |
       |         |eth0/5         eth0/4|         |                 eth0/6 |        |
       + --------+                     |         |                        |        |
                                       +----+----+                        +--------+
                                            |eth0/3
                                            |
                                            |
                                            |
                                            |
                                            |eth0/8
                                      +----++------+
                                      |            |
                                      |   R2       |
                                      |            |
                                      |            |
                                      +------------+

#endif

    graph *topo2=create_graph("second_graph");
    DLL *D1=create_node(topo2,"R1");
    DLL *D2=create_node(topo2,"R2");
    DLL *D3=create_node(topo2,"R3");
    DLL *D4=create_node(topo2,"R4");
    DLL *S1=create_node(topo2,"S1");


    insert_link_between_nodes(D1->N, S1->N, "eth0/5", "eth0/4", 1);
    insert_link_between_nodes(D2->N, S1->N, "eth0/8", "eth0/3", 1);
    insert_link_between_nodes(D3->N, S1->N, "eth0/6", "eth0/2", 1);
    insert_link_between_nodes(D4->N, S1->N, "eth0/7", "eth0/1", 1);
    return topo2;
}

graph *third_topology()
{

#if 0

    +-----------+                      +--------+                            +--------+
    |           |eth0/0                |        | eth0/2               eth0/3|        |
    | R1        +----------------------|  R2    +----------------------------+   R3   |
    |           |eth0/1                |        |                            |        |
    +---+--+----+                      |        |                            +        +
           |eth0/7                     +--------+                            +----+---+
           |                                                                      | eth0/4
           |                                                                      |
           |                                                                      |
           |                                                                      |
           |                                                                      |
           |                                                                      |
           |                                                                      |
           |                          +-----------+                               |
           |                          |           |                               |
           |                  eth0/6  |  R4       |                               |
           +--------------------------+           |                               |
                                      |           +-------------------------------+
                                      |           |eth0/5
                                      +-----------+

#endif

    graph *topo3=create_graph("third_graph");
    DLL *D1=create_node(topo3,"R1");
    DLL *D2=create_node(topo3,"R2");
    DLL *D3=create_node(topo3,"R3");
    DLL *D4=create_node(topo3,"R4");

    insert_link_between_nodes(D1->N, D2->N, "eth0/0", "eth0/1", 1);
    insert_link_between_nodes(D2->N, D3->N, "eth0/2", "eth0/3", 1);
    insert_link_between_nodes(D3->N, D4->N, "eth0/4", "eth0/5", 1);
    insert_link_between_nodes(D4->N, D1->N, "eth0/6", "eth0/7", 1);

    return topo3;

}

graph *fourth_topology()
{
#if 0
                                    +---------+                               +----------+
                                    |         |                               |          |
                                    |  R2     |                               |  R5      |
                                    |         |                               |          |
                                    +---+-----+                               +-----+----+
                                        |                                           +
                                        |eth0/3                                     |eth0/8
                                        |                                           |
                                        |eth0/7                                     |eth0/9
                                  +-----+----+                                +-----+---+
                                  |          |                                |         |
   +------+---+                   |          |                                |         |                         +--------+
   |  R1      |                   |     S1   |eth0/5                    eth0/7|    S2   |eth0/10           eth0/11|  R6    |
   |          +-------------------|          |+-------------------------------|         +-------------+----------+|        |
   +------+---+ eth0/1      eth0/2|          |                                |         |                         |        |
                                  |          |                                |         |                         +-+------+
                                  +-----+----+                                +----+----+
                                        |eth0/6                                    |eth0/12
                                        |                                          |
                                        |                                          |
                                        |                                          |
                                        |                                          |
                                        |                                          |eth0/11
                                        |eth0/4                                    |
                                        |                                        +--+-----+
                                   +----+---+|                                   | R4     |
                                   |  R3     |                                   |        |
                                   |         |                                   |        |
                                   +--------+|                                   +--------+
#endif

    graph *topo4=create_graph("fourth_graph");
    DLL *D1=create_node(topo4,"R1");
    DLL *D2=create_node(topo4,"R2");
    DLL *D3=create_node(topo4,"R3");
    DLL *D4=create_node(topo4,"R4");
    DLL *D5=create_node(topo4,"R5");
    DLL *D6=create_node(topo4,"R6");
    DLL *S1=create_node(topo4,"S1");
    DLL *S2=create_node(topo4,"S2");

    insert_link_between_nodes(D1->N, S1->N, "eth0/1", "eth0/2", 1);
    insert_link_between_nodes(D2->N, S2->N, "eth0/3", "eth0/7", 1);
    insert_link_between_nodes(D3->N, S1->N, "eth0/4", "eth0/6", 1);
    insert_link_between_nodes(S1->N, S2->N, "eth0/5", "eth0/7", 1);
    insert_link_between_nodes(D5->N, S2->N, "eth0/8", "eth0/9", 1);
    insert_link_between_nodes(D4->N, S2->N, "eth0/11", "eth0/12", 1);
    insert_link_between_nodes(D6->N, S2->N, "eth0/11", "eth0/10", 1);
    return topo4;
}

