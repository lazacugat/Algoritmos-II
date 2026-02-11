#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    stack test1 = stack_empty();
    bool b = stack_did_pop_when_size_eq_1(test1);
    fprintf(stdout, "The function stack_pop works correctly when stack_size == 1 : %d\n",b);
    free(test1);

    stack test2= stack_empty();
    b = stack_to_array_did_return_null_if_stack_is_empty(test2);
    fprintf(stdout, "The function stack_to_array returns array = null when stack is empty : %d\n",b);
    free(test2);

    stack test3 = stack_empty();
    test3 = stack_push(test3,1);
    b = stack_did_push_after_a_pop_when_size_eq_0(test3);
    fprintf(stdout, "The function stack_push works correctly after the function pop makes NULL the stack : %d\n",b);
    free(test3);

    stack test4 = stack_empty();
    test4 = stack_push(test4,1);
    test4 = stack_push(test4,2);
    stack_elem *a = stack_to_array(test4);
    b = stack_to_array_did_return_elemns_in_order(test4);
    fprintf(stdout, "The function stack to array returns the elemens in order : %d\n",b);
    free(test4);
}