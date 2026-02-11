#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "test.h"

bool stack_did_pop_when_size_eq_1(stack s)
{
    assert(stack_size(s) == 0);
    s = stack_push(s, 1);
    assert(stack_size(s) == 1);
    s = stack_pop(s);
    if (stack_is_empty(s))
    {
        return (true);
    }
    fprintf(stderr, "Stack did not pop when the size was 1\n");
    return false;
}

bool stack_did_push_after_a_pop_when_size_eq_0(stack s)
{
    assert(stack_size(s) == 1);
    s = stack_pop(s);
    assert(stack_size(s) == 0);
    s = stack_push(s, 1);
    if (!stack_is_empty(s) && stack_top(s) == 1)
    {
        return true;
    }
    fprintf(stderr, "Stack did not push after making the stack null with a pop \n");
    return false;
}

bool stack_to_array_did_return_null_if_stack_is_empty(stack s)
{
    assert(stack_is_empty(s));
    stack_elem *array = stack_to_array(s);
    if (array == NULL)
    {
        return true;
    }
    fprintf(stderr, "Stack to array did not return null when the stack is empty\n");
    return false;
}

bool stack_to_array_did_return_elemns_in_order(stack s)
{
    assert(!stack_is_empty(s));
    int *array = stack_to_array(s);
    stack p = s;
    for (unsigned int i = stack_size(s); i < stack_size(s); i++)
    {
        if (stack_top(s) != array[i])
        {
            fprintf(stderr, "Stack to array did not return the elemens in order\n");
            free(array);
            return false;
        }
        p = stack_pop(p);
    }
    free(array);
    return true;
}
