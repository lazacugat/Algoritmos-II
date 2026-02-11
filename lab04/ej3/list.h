#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct _node * list;
typedef int list_elem;

list empty_list(void);
/* creates an empty list */

list addl_list(list_elem e, list l);
/* Adds an element at the beginning of a list l */

list destroy_list(list l);
/* Free the memory if it is necessary */

bool is_empty_list(list l);
/* Returns True if l is an empty list */

list_elem head(list l);
/* Returns the first element of a list l */
/* PRE: not is_empty(l) */

list tail(list l);
/* Voids the first element in a list l */
/* PRE: not is_empty(l) */

list addr(list l, list_elem e);
/* Adds an element at the end of a list l */

int length_list(list l);
/* Returns the amount of elements in a list l */

list concat(list l0, list l1);
/* Adds at the end of l0 all the elements of l1 in the same order*/

list_elem index(list l, int n);
/* Returns the element in the position n of a list l */
/* PRE: length(l) > n */

list take(list l, int n);
/* Takes the elements of l previous the position n and deletes the others */
/* PRE: length(l) > n */

list drop(list l, int n);
/* Deletes the elements in the position before n of a list l */

list copy_list(list l);
/* Copies all the elements of a list l to a new list */

#endif
