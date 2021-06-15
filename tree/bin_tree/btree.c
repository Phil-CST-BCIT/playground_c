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

    return n % 2 != 0 ? (n - 1) / 2 : (n - 2) / 2;

}

int steps(int n) {

    int s = 0;

    while(n > 0) {

        ++s;

        n = compass(n);

    }

    return s;

}

int* road_map(int i) {
    
    int s = steps(i);;

    int* rm = (int*) calloc(s, sizeof(int));

    if(!rm) {
    
        printf("free store allocation failed!");
    
        exit(-1);
    
    }

    int* tmp = rm;

    while(s > 0) {

        --s;

        i = compass(i);

        *(tmp + s) = i;

        printf("%d\n", *(tmp+s));

    }

    return rm;

}

/* this version inserts a node into a balanced binary tree.
   Rule: we check the left sub tree first, if the left is full, we insert the node into the right sub tree
   solution: create a static or external int variable and increment the variable by one when we insert one node 

 e.g. we insert 6 into [1, 2, 3, 4, 5]
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
BTree* insert_node_bal(BTree* root, int data) {

    static int number_nodes;

    // if the root is null, we create a new node, increment the counter by one and return the new node
    // else 
    //     1. we know the number of nodes
    //     2. we need to know how to go to the last leaf
    //     3. the index of the new node will be the number of current nodes
    //     4. get the index of its parent

    if(!root) {

        BTree* tmp = create_node(data);

        ++number_nodes;

        printf("%d\n", number_nodes);

        return tmp;

    }

    int new_index = number_nodes;

    int* rm = road_map(new_index);

    // create a tmp node pointer and assign root to the pointer
    // start from 0, if the element in rm is an odd number, go left, else go right
    // stop at the last element
    // if new_index is odd, insert left, else insert right


    // return NULL;
}

int main() {

    // BTree* root = create_node(0);

    // print_ascii_tree(root);

    // insert_node(root, 1);

    // print_ascii_tree(root);

    // insert_node_bal(root, 1);
    // insert_node_bal(root, 2);

    // print_ascii_tree(root);

    // free_tree(root);

    int* rm = road_map(4);

    int s = steps(4);

    free(rm);

    return 0;

}
