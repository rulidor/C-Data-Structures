#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    void* data;
    struct Node* next;
};

void insert_at_beginning(struct Node **head, void* data, size_t data_size);
void insert_at_end(struct Node **head, void* data, size_t data_size);
void delete_by_index(struct Node *head, int index); //todo
void print_list(struct Node *head, char format);


void insert_at_beginning(struct Node **head, void* data, size_t data_size){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
    for (int i = 0; i < data_size; i++){
        *((char *)(new_node->data) + i) = * ((char *)(data) + i);
    }

    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node **head, void* data, size_t data_size){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->next = NULL; //new node is going to be the last node
    new_node->data = malloc(data_size);
    for (int i = 0; i < data_size; i++){
        *((char *)(new_node->data) + i) = * ((char *)(data) + i);
    }

    if (*head == NULL){
        *head = new_node;
        return;
    }

    struct Node* tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp -> next;
    }

    tmp->next = new_node;
}

void print_list(struct Node *head, char format){
    struct Node* tmp = head;
    while (tmp != NULL){
        switch (format)
        {
        case 's':
            printf("--> %s", *(char*)(tmp->data)); //todo: check if casting to pointer to string needed: char**
            break;

        case 'd':
            printf("--> %d", *(int*)(tmp->data));
            break;
        
        default:
            break;
        }

        tmp = tmp->next;
    }
}




int main(){
    struct Node* head = NULL;
    int data = 10;
    void* p_data = &data;
    insert_at_beginning(&head, p_data, sizeof(int));
    data = 20;
    insert_at_beginning(&head, p_data, sizeof(int));
    data = 30;
    insert_at_beginning(&head, p_data, sizeof(int));

    data = 7;
    insert_at_end(&head, p_data, sizeof(int));
    data = 3;
    insert_at_end(&head, p_data, sizeof(int));

    print_list(head, 'd');
}

