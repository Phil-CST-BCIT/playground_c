#define MAX_HEIGHT 1000
#define INFINITY (1 << 20)
#define MAX(x, y) ((x) > (y) ? (x) :(y))
#define MIN(x, y) ((x) < (y) ? (x) :(y))

#ifndef _ASCII_TREE_H_
#define _ASCII_TREE_H_

typedef struct ascii_node {

    struct ascii_node* left, * right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int lablen;

    //left: -1, root: 0, right: 1   
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
