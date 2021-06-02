#include <stdio.h>
#include <stdlib.h>

/** 
 * Note
 * 1. No matter what data type is, the size of a pointer is 64 bits for a 64-bit machine
 * 2. operations
    2.1 create
    2.2 add
    2.3 find
    2.4 length
    -2.5 add_at
    -2.6 remove
    -2.7 remove_at
    2.8 remove_head
    2.9 get
 *
 **/

struct node 

{

    int data;

    struct node* next;

};

typedef struct node Node;

Node* create_node() 

{
    
    Node* temp = (Node*)calloc(1, sizeof(Node));

    if(temp == NULL) 
    
    {
    
        printf("calloc failed");
    
        exit(-1);
    
    }

    temp->next = NULL;

    return temp;
}

Node* add_node(Node* head, int n) 

{

    Node* new_node = create_node();

    new_node-> data = n;

    if(head == NULL) 
    
    {
    
        return new_node;
    
    }

    Node* temp = head;

    while(temp->next != NULL) 
    
    {
    
        temp = temp->next; 
    
    }

    temp->next = new_node;

    return head;

}

Node* find_node(int n, Node* head) 

{

    if (head == NULL) 
    
    {
        return NULL;
    }

    Node* temp = head;

    while(temp != NULL) 
    
    {
        
        if(temp->data == n)
            return temp;
        
        temp = temp->next;

    }

    return NULL;

}

size_t length(Node* head) 

{
    size_t len = 0;

    if(head == NULL) 
    
    {
        return len;
    }

    Node* temp = head;

    while(temp != NULL)

    {
        len += 1;

        temp = temp->next;

    }

    return len;

}


void free_list(Node* head) 

{

    Node* temp = NULL;

    while(head != NULL) 
    
    {
        
        temp = head;
        
        head = head->next;

        free(temp);
        
    }

}

Node* remove_head(Node* head) 

{

    if(head == NULL)
        return NULL;

    Node* temp = head->next;

    head->next = NULL;

    free(head);

    return temp;

}

Node* get(Node* head, size_t i) {

    /** recursive approach */
    if( i < 0 || i >= length(head))
        return NULL;

    if(!i)
        return head;

    --i;

    return get(head->next, i);

    /** iterative approach */
    // Node* temp = head;

    // size_t j = 0;

    // while(temp != NULL) {

    //     if(i == j)
    //         return temp;

    //     ++j;

    //     temp = temp->next;

    // }

    // return NULL:

}

int main() 

{

    Node* head = NULL;

    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = add_node(head, 5);
    head = add_node(head, 6);

    Node* n = get(head, 10);

    if(n==NULL)
        printf("null\n");
    else
        printf("not null\n");

    free_list(head);

    return 0;

}