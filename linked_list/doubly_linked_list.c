#include <stdio.h>
#include <stdlib.h>

/** 
 * Note
 * 1. No matter what data type is, the size of a pointer is 64 bits for a 64-bit machine
 * 2. the size of node is 24 bytes not 20 bytes because of alignment.
 * 3. operations
 *   3.1 create
     3.2 add_front: create and add an element at the front of a DLL
 *
 **/

 struct node{
     long data;
     struct node* next; // align 8 bytes
     struct node* prev;
 };

 typedef struct node DLL;

DLL* create_node(long data) {

    // calloc returns a pointer to space for an n objects, each of the size of the type/struct, 
    // or NULL if the request cannot be satisfied.
    // The space is initialized to zero bytes.
    DLL* node = (DLL*)calloc(1, sizeof(DLL));

    if(!node) {
        printf("free store allocation failed");
        exit(-1);
    }

    node->data = data;

    node->next = NULL;

    node->prev = NULL;

    return node;

}

DLL* add_front(DLL* head, int data) {

    DLL* n = create_node(data);

    if(!head)
        return n;


    head->prev = n;

    n->next = head;

    return n;

}

void free_list(DLL* head) {

    if(head) { /* but we don't know if head is safe */

        free(head);

        free_list(head->next);

    }

}

int main() {

    DLL* head = create_node(0);

    head = add_front(head, -1);
    
    printf("the data in head is %ld\n", head->data);
    printf("the data in head->next is %ld\n", head->next->data);


    free_list(head);

    return 0;
}