#include "List.h"
#include "dynamicArray.h"
#include "merge.h"
#include <stdio.h>
#include <assert.h>

int equals(List* list, List* list1) {

    Iterator* iterator = create_list_iterator(list, 0);
    Node* node = get_list_iter_Elem(iterator);

    Iterator* iterator1 = create_list_iterator(list1, 0);
    Node* node1 = get_list_iter_Elem(iterator1);

    if (list->size != list->size)
        return 0;

    while (done_iteration(iterator) != 1)
    {
        if (node->value != node1->value)
            return 0;

        node = get_next_elem(iterator);
        node1 = get_next_elem(iterator1);

    }
    return 1;
}

int equals1(DArray* darray, DArray* darray1) {

    DArrayIterator* iterator = create_darray_iterator(darray);
    char* elem = get_darray_iteration_elem(iterator);

    DArrayIterator* iterator1 = create_darray_iterator(darray1);
    char* elem1 = get_darray_iteration_elem(iterator1);

    if (darray->size != darray1->size || darray->elementsize != darray1->elementsize)
        return 0;

    while (done_darray_iteration(iterator) != 1) {

        if (*elem != *elem1)
            return 0;
        elem = next_darray_iteration(iterator);
        elem1 = next_darray_iteration(iterator1);

    }
    return 1;
}

int equals1double(DArray* darray, DArray* darray1) {

    DArrayIterator* iterator = create_darray_iterator(darray);
    double* elem = get_darray_iteration_elem(iterator);

    DArrayIterator* iterator1 = create_darray_iterator(darray1);
    double* elem1 = get_darray_iteration_elem(iterator1);

    if (darray->size != darray1->size || darray->elementsize != darray1->elementsize)
        return 0;

    while (done_darray_iteration(iterator) != 1) {

        if (elem != elem1)
            return 0;
        elem = next_darray_iteration(iterator);
        elem1 = next_darray_iteration(iterator1);

    }
    return 1;
}

void testEmptyl() {

    List* l = create_list();
    List* l1 = create_list();
    remove_node(l, 3);
    assert(1 == equals(l, l1));
    pop_node(l);
    assert(1 == equals(l, l1));
    insert_node(l, create_node(4), 5);
    push_node(l1, create_node(4));
    assert(1 == equals(l, l1));

}

void testgetlist() {

    List* l = create_list();
    push_node(l, create_node('a'));
    push_node(l, create_node('b'));
    push_node(l, create_node('c'));
    push_node(l, create_node('d'));
    assert('c' == get_node(l, 2)->value);
    assert(NULL == get_node(NULL, 2));
    
}

testdeletelist() {

    List* l = create_list();
    push_node(l, create_node('a'));
    push_node(l, create_node('b'));
    push_node(l, create_node('c'));
    push_node(l, create_node('d'));
    remove_node(l, 2);
    List* l1 = create_list();
    push_node(l1, create_node('a'));
    push_node(l1, create_node('b'));
    push_node(l1, create_node('d'));
    assert(1 == equals(l, l1));
}

void testinsertlist() {

    List* l = create_list();
    push_node(l, create_node('a'));
    push_node(l, create_node('b'));
    push_node(l, create_node('d'));
    insert_node(l, create_node('c'), 2);
    List* l1 = create_list();
    push_node(l1, create_node('a'));
    push_node(l1, create_node('b'));
    push_node(l1, create_node('c'));
    push_node(l1, create_node('d'));
    assert(1 == equals(l, l1));
}

void testEmptyda(){

    DArray* d1 = create_darray(3, sizeof(char));
    DArray* d2 = create_darray(3, sizeof(char));
    delete_element_darray(d1, 3);
    assert(1 == equals1(d1, d2));
    char a = 'a', b = 'b', c = 'c';
    push_darray(d1, &c);
    pop_darray(d1);
    assert(1 == equals1(d1, d2));
    assert(1 == is_darray_empty(d1));
    push_darray(d1, &a);
    push_darray(d1, &b);
    push_darray(d1, &c);

}

void testgetda() {

    DArray* d1 = create_darray(3, sizeof(char));
    char a1 = 'a', b1 = 'b', c1 = 'c', dd1 = 'd';
    push_darray(d1, &a1);
    push_darray(d1, &b1);
    push_darray(d1, &c1);
    push_darray(d1, &dd1);
    char* test1 = get_element_darray(d1, 2);
    assert('c' == *test1);
    assert(NULL == get_element_darray(d1, 6));

    DArray* d2 = create_darray(3, sizeof(double));
    double a = 2.4, b = 3.2, c = 2.1, d = 8.2;
    push_darray(d2, &a);
    push_darray(d2, &b);
    push_darray(d2, &c);
    push_darray(d2, &d);
    double* test = get_element_darray(d2, 2);
    assert(2.1 == *test);
    assert(NULL == get_element_darray(d2, 6));
}

void testdeleteda() {

    DArray* d1 = create_darray(3, sizeof(char));
    char a1 = 'a', b1 = 'b', c1 = 'c', dd1 = 'd';
    push_darray(d1, &a1);
    push_darray(d1, &b1);
    push_darray(d1, &c1);
    push_darray(d1, &dd1);
    delete_element_darray(d1, 2);
    char* test = get_element_darray(d1, 2);
    assert('d' == *test);
    assert(3 == get_darray_size(d1));
    delete_element_darray(d1, 10);
    char* test1 = get_element_darray(d1, get_darray_size(d1) - 1);
    assert('b' == *test1);

}

void testinsertda() {

    DArray* d1 = create_darray(3, sizeof(char));
    char a1 = 'a', b1 = 'b', c1 = 'c', dd1 = 'd', k = 'k';
    push_darray(d1, &a1);
    push_darray(d1, &b1);
    push_darray(d1, &c1);
    push_darray(d1, &dd1);
    insert_darray(d1, &k, 2);
    DArray* d2 = create_darray(3, sizeof(char));
    char a2 = 'a', b2 = 'b', c2 = 'c', dd2 = 'd', k2 = 'k';
    push_darray(d2, &a2);
    push_darray(d2, &b2);
    push_darray(d2, &k2);
    push_darray(d2, &c2);
    push_darray(d2, &dd2);
    assert(1 == equals1(d1, d2));
}

void testMerge() {

    DArray* darray = create_darray(4, sizeof(int));
    int a = 1, b = 4, c = 7;
    push_darray(darray, &a);
    push_darray(darray, &b);
    push_darray(darray, &c);

    DArray* darray1 = create_darray(4, sizeof(int));
    int d = 2, e = 3, f = 7, g = 9;
    push_darray(darray1, &d);
    push_darray(darray1, &e);
    push_darray(darray1, &f);
    push_darray(darray1, &g);

    DArray* t = create_darray(8, sizeof(int));
    int a1 = 1, b1 = 2, c1 = 3, d1 = 4, e1 = 7, f1 = 7, g1 = 9;
    push_darray(t, &a1);
    push_darray(t, &b1);
    push_darray(t, &c1);
    push_darray(t, &d1);
    push_darray(t, &e1);
    push_darray(t, &f1);
    push_darray(t, &g1);

    assert(1 == equals1(t, merge_Sorted_DArrays(darray, darray1,0)));
}

int main(int argc, char** argv) {

    testEmptyl();
    testgetlist();
    testdeletelist();
    testinsertlist();

    testEmptyda();
    testgetda();
    testdeleteda();
    testinsertda();
    //testMerge();
    return 0;
}