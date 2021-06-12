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
        printf("allocation failed in create_node function");
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

// we assume the binary tree is a binary search tree because it's easier to implement the insert function
// returns a pointer to the inserted node
BTree* insert_node(BTree* root, int data) {

    if(!root) {
        
        BTree* tmp = create_node(data);

        return tmp;
    
    }

    if(data <= root->data) {
        
        BTree* n = insert_node(root->left, data);

        root->left = n;

        return n;
    }

    else if(data > root->data) {
        
        BTree* n = insert_node(root->right, data);

        root->right = n;

        return n;

    } else { /* we don't really need this else block, but we can use this as a gate keeper in case anything went wrong */

        return NULL;

    }

}

// this version inserts a node into a balanced binary tree.
// Rule: we check the left sub tree first, if the left is full, we insert the node into the right sub tree

/* e.g. we insert 6 into [1, 2, 3, 4, 5]

 * before:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 
 * after: 
 *         1
 *        / \
 *       /   \
 *      2     3
 *     / \   /
 *    4   5 6
*/
BTree* insert_node_bal() {

}

int main() {

    BTree* root = create_node(0);

    print_ascii_tree(root);

    insert_node(root, 1);

    print_ascii_tree(root);

    free_tree(root);

    return 0;

}
