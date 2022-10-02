#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../linked_list/linked_list.h"

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


// *****functions implementation*****

void print_stack(struct Node* top, char format){
    struct Node* tmp = top;
    while (tmp != NULL){
        printf("--> value: ");
        switch (format)
        {
        case 's':
            printf("%s", *(char**)(tmp->data));
            break;

        case 'd':
            printf("%d", *(int*)(tmp->data));
            break;
        
        default:
            break;
        }

        tmp = tmp->next;
    }
}

void push(struct Node** top, void* data, size_t data_size){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
    for (int i = 0; i < data_size; i++){
        *((char*)(new_node->data) + i) = *((char*)(data) + i);
    }
    new_node->next = *top;
    *top = new_node;
}

int is_empty(struct Node* top){
    if (top == NULL){
        return 1;
    }
    return 0;
}

void* pop(struct Node** top){
    if (*top == NULL){
        return NULL;
    }
    void* res_data = (*top)->data;
    *top = (*top)->next;
    return res_data;
}

void* top(struct Node* top_node){
    if (top_node == NULL){
        return NULL;
    }
    return top_node->data;
}

int get_size(struct Node* top){
    struct Node* tmp = top;
    int counter = 0;
    while (tmp != NULL){
        counter += 1;
        tmp = tmp->next;
    }
    return counter;
}



int main(){

    struct Node* my_stack = NULL;
    char* num = "1";
    char** pnum = &num;
    push(&my_stack, pnum, sizeof(num));
    num = "2";
    push(&my_stack, pnum, sizeof(num));
    num = "3";
    push(&my_stack, pnum, sizeof(num));
    num = "4";
    push(&my_stack, pnum, sizeof(num));

    print_stack(my_stack, 's');

    
}