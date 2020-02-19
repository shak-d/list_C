#ifndef LIST_H
#define LIST_H

#include <stdlib.h>


//single element structre
typedef struct Node {

    void* value;
    
    //next linked element
    struct Node* next;

    //previous linked element
    struct Node* previous;

}Node;

typedef struct List {

    //first element
    struct Node* first;

    //last element
    struct Node* last;

    //list size
    int size;

}List;

typedef struct Iterator {

    //Container to iterate
    List* container;

    //Current element
    void* current;
   
}Iterator;

//Creates a new node
Node* create_node(void* value);

//check if the list is empty, 1 if empty
int is_list_empty(List* list);

//inserts a node in a list in a specific location, 1 if successful
int insert_node(List* list, Node* node, int index);

//adds the node at the end of the list, 1 if successful
int push_node(List* list, Node* node);

//removes the last element from the list and returns it
Node* pop_node(List* list);

//removes the element if a specific position from the list, 1 if successful
int remove_node(List* list, int index);

//cleans up the memory from the node
void delete_node(Node* node);

//returns a specific node from a given list
Node* get_node(List* list, int index);

//Creates an empty list
List* create_list();

//cleans up the memory from the list and nodes
void delete_list(List* list);

//return the list size
int get_list_size(List* list);

//returns a new iterator with given container and first element
Iterator* create_list_iterator(List* list, int first);

//returns the current element from the iterator
Node* get_list_iter_Elem(Iterator* iterator);

//returns the next element from the container
Node* get_next_elem(Iterator* iterator);

//returns 1 if list end reached
int done_iteration(Iterator* iterator);

//clean up the iterator from the memory
void delete_iterator(Iterator* iterator);

#endif // !LIST_H
