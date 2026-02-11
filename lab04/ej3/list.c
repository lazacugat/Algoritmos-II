#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"
#include <stdlib.h>

struct _node
{
    list_elem elem;
    struct _node *next;
};

list empty_list(void){
    return NULL;
}

list addl_list(list_elem e, list l){
    struct _node *l1;
    l1 = malloc(sizeof(struct _node));
    l1->next = l;
    l1->elem = e;
    return l1;
}

list destroy_list(list l){
    if (!is_empty_list(l))
    {
        destroy_list(l->next);
        free(l);
    }
    return l;
}

bool is_empty_list(list l){
    return (l == NULL);
}

list_elem head(list l){
    assert(!is_empty_list(l));
    list_elem head = l->elem;
    return head;
}

list tail(list l) {
    assert(l != NULL);
    return l->next;
}


list addr(list l, list_elem e){
    list new_elem;
    new_elem = malloc(sizeof(struct _node));
    new_elem->elem = e;
    new_elem->next = NULL;
    if (!is_empty_list(l))
    {
        list l1 = l;
        while (!is_empty_list(l1->next))
        {
            l1 = l1->next;
        }
        l1->next = new_elem;
    }
    else
        l = new_elem;
    return l;
}

int length_list(list l){
    list l1;
    l1 = l;
    unsigned int value=0u;
    if (!is_empty_list(l1))
    {
        value = 1 + length_list(l1->next);
    }
    return value;
}

list concat(list l0, list l1){
    if (!is_empty_list(l1))
    {
        concat(addr(l0,head(l1)),tail(l1));
    }
    return l0;
}


list_elem index(list l, int n){
    assert((length_list(l) > n));
    list l1 = l;
    while (n > 0)
    {
        l1 = l1->next;
        n--;
    }
    return l1->elem;
}


list take(list l, int n){
    assert(length_list(l) > n);
    if (n == 0)
    {
        l = destroy_list(l);
    }
    else
    {
        list l1;
        for (int i = 1; i < n; i++)
        {
            l1 = l1->next;
        }
        l1->next = NULL;
    }
    return l;
}


list drop(list l, int n){
    if (n > length_list(l))
    {
        return empty_list();
    }
    else
    {
        list l1 = l;
        for (int i = 0; i < n; i++)
        {
            l1 = l1->next;
        }
        free(l);
        return l1;
    }
}

list copy_list(list l){
    list l1 = empty_list();
    if (!is_empty_list(l))
    {
        l1 = addr(l1,head(l));
        l1->next = copy_list(l->next);
    }    
    return l1;
}