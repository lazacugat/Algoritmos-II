#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack
{
    stack_elem elem;
    struct _s_stack *stack;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack new = malloc(sizeof(struct _s_stack));
    new->elem = e;
    new->stack = s;
    s = new;
    return s;
}

stack stack_pop(stack s){
    assert(stack_size(s) > 0);
    stack p;
    p = s;
    s = s->stack;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int size = 0;
    stack p = s;
    if (!stack_is_empty(p))
    {
        size = 1u + stack_size(p->stack);
    }
    return size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    unsigned int size = stack_size(s);
    if (size == 0)
    {
        return NULL;
    }
    
    stack_elem *array = malloc(sizeof(stack_elem)*size);
    stack p = s;
    while (!stack_is_empty(p) && size > 0)
    {
        array[size-1] = p->elem;
        size --;
        p = p->stack;
    }
    return array;
}

stack stack_destroy(stack s){
    if (!stack_is_empty(s))
    {
        s = stack_destroy(s->stack);
    }
    free(s);
    return s;
}