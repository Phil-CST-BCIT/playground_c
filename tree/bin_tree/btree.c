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

int compass(int n) {

    return n % 2 != 0 ? (n - 1) / 2 : (n - 2) / 2;

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

    /* somewhere in the code has mem leak */

    static int number_nodes;

    if(!root) {

        BTree* tmp = create_node(data);

        ++number_nodes;

        printf("%d\n", number_nodes);

        return tmp;

    }

    int i, j, num_steps = 0;

    i = number_nodes;

    while(i != 0) {
        
        i = compass(i);
        
        ++num_steps;

    }

    int* road_map = (int*) calloc(num_steps, sizeof(int));

    if(!road_map) {
        printf("free store allocation failed");
        exit(-1);
    }

    j = num_steps;

    i = number_nodes;

    while(num_steps > 0) {

        i = compass(i);

        *(road_map + (num_steps - 1)) = i; // e.g. num_nodes = 3 -> [ 0, 1 ]

        --num_steps;
    }

    num_steps = j;

    int* tmp = road_map;

    BTree* tmp_node = root;

    while(num_steps > 0) {

        BTree* parent = tmp_node;

        if(*tmp == 0 && tmp_node->right) {

            tmp_node = tmp_node->left;

        } else if (*tmp % 2 == 0) {
            
            tmp_node = tmp_node->right;
            
            if(!tmp_node) {
            
                tmp_node = create_node(data);
            
                parent->right = tmp_node;
            
            }

        } else {
            
            tmp_node = tmp_node->left;
            
            if(!tmp_node) {
        
                tmp_node = create_node(data);
        
                parent->left = tmp_node;
            
            }
        }

        tmp += 1;

        --num_steps;
    }


    while(j > 0) {
        
        int* ip = road_map; // 0 1 2

        free(ip); // 0 1 2

        road_map += 1; // 1 2 3

        --j; // 2 1 0
        
    }

    return tmp_node;
}

int main() {

    BTree* root = create_node(0);

    // print_ascii_tree(root);

    // insert_node(root, 1);

    // print_ascii_tree(root);

    insert_node_bal(root, 1);
    insert_node_bal(root, 2);

    print_ascii_tree(root);

    free_tree(root);

    return 0;

}
