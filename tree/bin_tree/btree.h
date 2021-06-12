#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct tree_node {

    int data;

    struct tree_node* left;

    struct tree_node* right;

} BTree;

#endif