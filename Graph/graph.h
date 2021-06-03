//
// Created by Karthik Marri on 29/05/21.
// This is Header file which consists of definitions of all structures
// of each component
//

#ifndef TCP_IP_GRAPH_H
#define TCP_IP_GRAPH_H

#define MAX_INTERFACES_POSSIBLE 10

typedef struct double_linked_list_
{
    struct double_linked_list_ *left;
    struct double_linked_list_ *right;
    struct node_ *N;
}DLL;

typedef struct graph_
{
    char *topology_name;
    DLL *head;
}graph;

typedef struct interface_
{
    char *interface_name;
    struct node_ *parent;
    struct link_ *link;
}interface;

typedef struct node_
{
    char *node_name;
    interface *I[MAX_INTERFACES_POSSIBLE];
}node;

typedef struct link_
{
    interface i1;
    interface i2;
    int cost;
}link;

graph *create_graph(char *);
DLL *create_node(graph *,char *);
void insert_link_between_nodes(node*,node*,char*,char*,int);
void display_graph(graph*);

#endif //TCP_IP_GRAPH_H