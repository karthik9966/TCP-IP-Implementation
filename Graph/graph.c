//
// Created by Karthik Marri on 29/05/21.
// This file contains the implementation part of network graph
//

#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

int i=0;

graph *create_graph(char *s)
{
    graph *new_graph= (graph*) malloc(sizeof(graph));
    new_graph->topology_name=s;
    new_graph->head=NULL;
    return new_graph;
}

DLL *create_node(graph *topo,char *s)
{
    DLL *D=(DLL*) malloc(sizeof (DLL));
    D->right=NULL;
    D->left=NULL;
    node *n=(node*) malloc(sizeof(node));
    n->node_name=s;
    D->N=n;
    int i=0;
    while(i<MAX_INTERFACES_POSSIBLE)
    {
        n->I[i]=NULL;
        i++;
    }
    if(!topo->head)
        topo->head=D;
    else
    {
        DLL *temp=topo->head;
        topo->head=D;
        D->right=temp;
        temp->left=D;
    }
    return D;
}

static int get_node_intf_available_slot(node *n)
{
    int i=0;
    while(n->I[i])
        i++;
    return i;
}

void insert_link_between_nodes(node *n1,node *n2,char *name1,char *name2,int c)
{
    link *l= (link*) malloc(sizeof(link));
    l->i1.interface_name=name1;
    l->i2.interface_name=name2;
    l->i1.parent=n1;
    l->i2.parent=n2;
    l->i1.link=l;
    l->i2.link=l;
    l->cost=c;
    int i=get_node_intf_available_slot(n1);
    n1->I[i]=&l->i1;
    int j=get_node_intf_available_slot(n2);
    n2->I[j]=&l->i2;
}

static char * get_nbr_node(interface *ptr)
{
    link *l2=ptr->link;
    if(&l2->i1==ptr)
        return l2->i2.interface_name;
    else
        return l2->i1.interface_name;
}

void display_graph(graph* G)
{
    printf("Topology Name = %s\n",G->topology_name);
    DLL *t=G->head;
    while(t)
    {
        printf("Node Name = %s\n",t->N->node_name);
        int i=0;
        while(t->N->I[i])
        {
            printf(" Local Node : %s,",t->N->node_name);
            printf(" Interface Name = %s,",t->N->I[i]->interface_name);
            char *s=get_nbr_node(t->N->I[i]);
            printf(" Nbr Node %s,",s);
            printf(" Cost %d\n",t->N->I[i]->link->cost);
            i++;
        }
        t=t->right;
    }
}
