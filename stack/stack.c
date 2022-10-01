#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../linked_list/linked_list.h"

// Adds an item onto the stack.
void push(struct Node* top, void* data);

// Returns the last item pushed onto the stack.
struct Node* top(struct Node* top_node);

// Removes the most-recently-pushed item from the stack.
struct Node* pop(struct Node* top);

// Returns 1 if stack is empty. Else, returns 0.
int is_empty(struct Node* top);

// Returns the number of elements in the stack.
int get_size(struct Node* top);