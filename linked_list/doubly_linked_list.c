#include <stdio.h>
#include <stdlib.h>

/** 
 * Note
 * 1. No matter what data type is, the size of a pointer is 64 bits for a 64-bit machine
 * 2. the size of node is 24 bytes not 20 bytes because of alignment.
 * 3. the online tutorials use two external variables to store head and tail 
 
 *   operations
 *   1. create
     2. add_front: create and add an element at the front of a DLL
     3. add_back
     4. print
     5. add_after
     6. length
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

// returns the pointer to the tail
// if we have an external variable holding the tail, then this function will be an O(1) operation
DLL* add_back(DLL* head, int data) {

    DLL* n = create_node(data);

    if(!head)
        return n;

    DLL* tmp = head;

    while(tmp->next) {

        tmp = tmp->next;

    }

    tmp->next = n;

    return n;    

}

void print(DLL* head) {

    if(head) {
        printf("%ld -> ", head->data);
        print(head->next);
    }
    else
        printf("NULL\n");

}

size_t length(DLL* head) {

    if(!head)
        return 0;

    size_t l = 1;
    
    DLL* tmp = head;

    while(tmp->next) {
        
        ++l;

        tmp = tmp->next;
    
    }

    return l;
}

bool add_after(DLL* head, int data, size_t position) {

    if(position < 0 )
        return false;

    else if(position > 0 && head->next)
        return add_after(head->next, data, --position);
    
    else {

        DLL* n = create_node(data);

        if(!head->next){
            head->next = n;
            return true;
        } else {

            n->prev = head;
            n->next = head->next;
            head->next->prev = n;
            head->next = n;
            
            return true;
        }
        
    }

    

    

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

    DLL* tail = add_back(head, 1);

    size_t l = length(head);

    print(head);

    printf("length = %lu\n", l);
    
    free_list(head);

    return 0;
}