#ifndef _ASCII_TREE_H_
#define _ASCII_TREE_H_

typedef struct tree_node {

    int data;

    struct tree_node* left;

    struct tree_node* right;

} BTree;

typedef struct ascii_node {

    struct ascii_node* left, * right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int lablen;

    //-1=I am left, 0=I am root, 1=right   
    int parent_dir;

    //max supported unit32 in dec, 10 digits max
    char label[11];
} ASCII_TREE;

ASCII_TREE* build_ascii_tree_recursive(BTree*);
ASCII_TREE* build_ascii_tree(BTree*);
void free_ascii_tree(ASCII_TREE*);
void compute_lprofile(ASCII_TREE*, int, int);
void compute_rprofile(ASCII_TREE*, int, int);
void compute_edge_lengths(ASCII_TREE*);
void print_level(ASCII_TREE*, int, int);
void print_ascii_tree(BTree*);

#endif
