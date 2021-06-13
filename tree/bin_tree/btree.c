#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
// #include "ascii_tree.h"

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

int compass(int n) {

    return n % 2 == 0 ? (n - 2) / 2 : (n - 1) / 2;

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

 * solution 1: we can store each node pointer in an array
 * solution 2: create a static or external int variable and increment the variable by one when we insert one node 
*/
BTree* insert_node_bal(BTree* root, int data) {

    // static int number_nodes;

    if(!root) {

        BTree* tmp = create_node(data);

        // ++number_nodes;

        printf("%d\n", number_nodes);

        return tmp;

    }

    // int* road_map = (int*) calloc(NUM_OF_STEPS, sizeof(int));

    // if(!road_map) {
    //     printf("free store allocation failed in insert node");
    //     exit(-1);
    // }

    // int tmp, i, j;
    
    // tmp = i = j = number_nodes;

    // while(!tmp) {

    //     tmp = compass(tmp);

    //     --index;

    //     *(road_map + index) = tmp;

    // }

    // while(j > 0) {
        
    //     int* ip = road_map; // 0 1 2

    //     free(ip) // 0 1 2

    //     road_map += 1; // 1 2 3

    //     --j; // 2 1 0
        
    // }

    return NULL;
}

int main() {

    // BTree* root = create_node(0);

    // print_ascii_tree(root);

    // insert_node(root, 1);

    // print_ascii_tree(root);

    // free_tree(root);

    return 0;

}
