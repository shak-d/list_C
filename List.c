#include "List.h"

Node* create_node(void* value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

int is_list_empty(List* list)
{
    if (list != NULL && list->size > 0)
        return 0;
    
    return 1;
}

int insert_node(List* list, Node* node, int index)
{
    if (list == NULL || index < 0 || node == NULL)
        return 0;

    if (index == 0) {

        node->next = list->first;
        list->first = node;
        list->size = list->size + 1;
        return 1;

    }

    if (list->size == 0) {
        push_node(list, node);
        return 1;
    }

    Node* current = list->first;

    for (int i = 0; i < list->size; i++) {
        
        if (i == index) {
            node->next = current;
            node->previous = current->previous;
            current->previous = node;
            if(node->previous != NULL && node->previous->next != NULL)
                node->previous->next = node;
            list->size = list->size + 1;
            return 1;

        }

        current = current->next;
    }

    return 0;
}

int push_node(List* list, Node* node)
{
    if(list == NULL || node == NULL)
        return 0;
    if (list->size == 0) {
    
        list->first = node;
        list->last = node;
        node->next = NULL;
        node->previous = NULL;
    }
    else {
        node->previous = list->last;
        list->last->next = node;
        list->last = node;
        node->next = NULL;
    }
    list->size = list->size + 1;

    return 1;
}

Node* pop_node(List* list)
{
    if (list == NULL || list->size == 0)
        return 0;

    Node* temp = list->last;
    if (list->last->previous != NULL) {
        list->last->previous->next = NULL;
        list->last = list->last->previous;
    }
    delete_node(temp);
    list->size = list->size - 1;
    return 1;
}

int remove_node(List* list, int index)
{
    if (list == NULL || index < 0 || list->size == 0)
        return 0;

    if (index == 0) {
        Node* n = list->first;
        list->first = list->first->next;
        delete_node(n);
        if(list->first != NULL)
            list->first->previous = NULL;

        return 1;
    }

    Node* current = list->first;

    for (int i = 0; i < list->size; i++) {

        if (i == index) {
        
            current->previous->next = current->next;
            if(current->next != NULL)
                current->next->previous = current->previous;
            list->size = list->size - 1;
            delete_node(current);
            return 1;

        }

        current = current->next;
    }

    return 0;
}

void delete_node(Node* node)
{
    free(node);
}

Node* get_node(List* list, int index)
{
    if(list == NULL || index < 0 || list->size == 0)
        return NULL;
    Node* current = list->first;
    for (int i = 0; i < list->size; i++) {
        
        if (i == index)
            return current;
        current = current->next;
    }

    return NULL;
}

List* create_list()
{
    List* list = malloc(sizeof(List));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

void delete_list(List* list)
{

    Node* node = list->first;
    for (int i = 0; i < list->size; i++) {
        
        Node* n = node;
        node = node->next;
        delete_node(node);
    
    }

    free(list);
    return;
}

int get_list_size(List* list)
{
    return list->size;
}


Iterator* create_list_iterator(List* list, int first)
{
    if (list == NULL || first < 0)
        return NULL;
    Iterator* iterator = malloc(sizeof(Iterator));
    iterator->container = list;
    iterator->current = get_node(list, first);

    return iterator;
}

Node* get_list_iter_Elem(Iterator* iterator)
{
    if (iterator == NULL)
        return NULL;

    return (Node*)(iterator->current);
}

Node* get_next_elem(Iterator* iterator)
{
    if (iterator == NULL)
        return NULL;
    if (iterator->current == NULL)
        return NULL;
    iterator->current = ((Node*)iterator->current)->next;

    return iterator->current;
}

int done_iteration(Iterator* iterator)
{
    if (iterator == NULL)
        return 1;

    if (iterator->current == NULL)
        return 1;
    else
        return 0;
}

void delete_iterator(Iterator* iterator) {

    free(iterator);

    return;
}