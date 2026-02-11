#ifndef _TEST_H_
#define _TEST_H_
#include "stack.h"

/// @brief Checks if the function stack_pop has any error if size is 1
/// @param s Stack with size 0
/// @return True if the function works correctly
bool stack_did_pop_when_size_eq_1(stack s);


/// @brief Checks if the function stack_psuh has any error if we apply a stack_pop function previously
/// @param s Stack with size 1
/// @return True if the function works corretly
bool stack_did_push_after_a_pop_when_size_eq_0(stack s);


/// @brief Checks if the array that return the function stack_to_array is NULL when the stack is empty
/// @param s Stack with size 0
/// @return True if the function works corretly
bool stack_to_array_did_return_null_if_stack_is_empty(stack s);


/// @brief Checks if the function stack_to_array copies in the correct order the array
/// @param s Stack with size > 0
/// @return True if the function works corretly 
bool stack_to_array_did_return_elemns_in_order(stack s);


#endif 