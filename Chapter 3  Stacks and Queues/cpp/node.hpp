#ifndef NODE_H
#define NODE_H

typedef struct node{
    int data;
    node* next;
    node(int val) : data(val), next(NULL){}
}node;

#endif