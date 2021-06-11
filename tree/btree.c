#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "ascii_tree.h"

/*
 * 1. leaks -atExit -- ./a.out | grep LEAK 
 *     we use the above command to detect memory leak.
 */


BTree* create_node(int data) {

    BTree* tmp = (BTree*) calloc(1, sizeof(struct tree_node));

    if(!tmp) {
        printf("allocation failed");
        exit(-1);
    }

    tmp->data = data;

    tmp->left = NULL;

    tmp->right = NULL;

    return tmp;

}

void free_tree(BTree* root) {

    if(root) {

        if(root->left)
            free_tree(root->left);
    
        if(root->right)
            free_tree(root->right);

        free(root);
    }

}

BTree* insert_node() {

}

int main() {


    BTree* root = create_node(0);

    print_ascii_tree(root);

    free_tree(root);

    return 0;

}
