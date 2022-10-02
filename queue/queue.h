#ifndef QUEUE_   /* Include guard */
#define QUEUE_

#include "../linked_list/linked_list.h"

struct Queue{
    struct Node* front;
    struct Node* rear;
};

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

#endif // QUEUE_