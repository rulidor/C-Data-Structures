#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

// Initializes an empty queue.
void initialize(struct Queue** queue);

// Process of adding an element to the end of the queue
void enqueue(struct Queue** queue, void* data, size_t data_size);

// Removes and returns front element in queue.
void* dequeue(struct Queue** queue);

// Get the element at the front of the queue without removing it
void* peek(struct Queue* queue);

// Returns 1 if queue is empty. Else, returns 0.
int is_empty(struct Queue* queue);

// Returns the number of elements in the queue.
int get_size(struct Queue* queue);

// Prints the queue.
void print_queue(struct Queue* queue, char format);

// *****functions implementation*****

// Initializes an empty queue.
void initialize(struct Queue** queue){
    (*queue) = malloc(sizeof(struct Queue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

void enqueue(struct Queue** queue, void* data, size_t data_size){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->next = NULL; // new node is the last node inserted
    new_node->data = malloc(data_size);
    for (int i = 0; i < data_size; i++){
        * ((char*)(new_node->data) + i) = * ((char*)(data) + i);
    }
    if (((*queue)->rear) == NULL){
        (*queue)->front = new_node;
        ((*queue)->rear) = new_node;
        return;
    }
    ((*queue)->rear)->next = new_node;
    ((*queue)->rear) = new_node;
}


void* dequeue(struct Queue** queue){
    if (((*queue)->front) == NULL){
        return NULL;
    }
    void* res_data = ((*queue)->front)->data;
    (*queue)->front = ((*queue)->front)->next;
    return res_data;
}


void* peek(struct Queue* queue){
    if (queue->front == NULL){
        return NULL;
    }
    return (queue->front)->data;
}


void print_queue(struct Queue* queue, char format){
    struct Node* tmp = queue->front;
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

int get_size(struct Queue* queue){
    struct Node* tmp = queue->front;
    int counter = 0;
    while (tmp != NULL){
        tmp = tmp->next;
        counter += 1;
    }
    return counter;
}

int is_empty(struct Queue* queue){
    if (queue->front == NULL){
        return 1;
    }
    return 0;
}


int main(){

    struct Queue* my_queue = NULL;
    initialize(&my_queue);
    char* str = "1";
    char** pstr = &str;
    size_t str_size = strlen(str);

    enqueue(&my_queue, pstr, sizeof(str));
    str = "2";
    enqueue(&my_queue, pstr, sizeof(str));
    str = "3";
    enqueue(&my_queue, pstr, sizeof(str));
    str = "4";
    enqueue(&my_queue, pstr, sizeof(str));
    print_queue(my_queue, 's');
    printf("\nsize before dequeue: %d\n", get_size(my_queue));
    dequeue(&my_queue);
    print_queue(my_queue, 's');
    printf("\nsize after dequeue: %d\n", get_size(my_queue));
    char* res = *(char**)(peek(my_queue));
    printf("element in front of the queue is: %s\n", res);
}