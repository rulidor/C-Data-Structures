#ifndef STACK_   /* Include guard */
#define STACK_

// Adds an item onto the stack.
void push(struct Node** top, void* data, size_t data_size);

// Returns the last item pushed onto the stack.
void* top(struct Node* top_node);

// Removes the most-recently-pushed item from the stack.
void* pop(struct Node** top);

// Returns 1 if stack is empty. Else, returns 0.
int is_empty(struct Node* top);

// Returns the number of elements in the stack.
int get_size(struct Node* top);

// Prints the stack.
void print_stack(struct Node* top, char format);

#endif // STACK_