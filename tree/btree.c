#include <stdio.h>
#include <stdlib.h>

/*
 * 1. leaks -atExit -- ./a.out | grep LEAK 
 *     we use the above command to detect memory leak.
 */

typedef struct tree_node {

    int data;

    struct tree_node* left;

    struct tree_node* right;

} BTree;

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

void print_tree(BTree* root) {

    

}

int main() {

    // BTree bt = {1, NULL, NULL};

    // printf("%d\n", bt.data);

    // char s[] = "hello world";
    // char m[] = "bye bye";
    // double d = 1.23456;

    // printf("%s %s\n", s, m);
    // printf("%-15s %s\n", s, m);
    // printf("%.3f\n", d);

    BTree* root = create_node(0);

    printf("root data = %d\n", root->data);

    free_tree(root);

    return 0;

}
