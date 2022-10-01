#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    void* data;
    char key[20];
    struct Node* next;
};

void insert_at_beginning(struct Node **head, void* data, size_t data_size, char* key);
void insert_at_end(struct Node **head, void* data, size_t data_size, char* key);
void delete_by_key(struct Node **head, char* key);
void delete_all_list(struct Node **head);
void print_list(struct Node *head, char format);
void free_node(struct Node* node);
struct Node* get_node_by_key(struct Node* head, char* key);

void free_node(struct Node* node){
    node->next = NULL;
    free(node->data);
    free(node);
}

void delete_all_list(struct Node **head){
    struct Node* tmp = *head;
    while(tmp != NULL){
        struct Node* next = tmp->next;
        free_node(tmp);
        tmp = next;
    }
    *head = NULL;
}


void insert_at_beginning(struct Node **head, void* data, size_t data_size, char* key){
    struct Node* new_node = malloc(sizeof(struct Node));
    strcpy(new_node->key, key);
    new_node->data = malloc(data_size);
    for (int i = 0; i < data_size; i++){
        *((char *)(new_node->data) + i) = * ((char *)(data) + i);
    }

    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node **head, void* data, size_t data_size, char* key){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->next = NULL; //new node is going to be the last node
    strcpy(new_node->key, key);
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
        printf("--> key: %s, value: ", tmp->key);
        switch (format)
        {
        case 's':
            printf("%s", *(char*)(tmp->data)); //todo: check if casting to pointer to string needed: char**
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

struct Node* get_node_by_key(struct Node* head, char* key){
    struct Node* tmp = head;
    while (tmp != NULL){
        if (strcmp(key, tmp->key) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}


void delete_by_key(struct Node **head, char* key){
    if (*head == NULL){
        return;
    }
    struct Node* tmp = *head;
    if (strcmp(key, tmp->key) == 0){
        if (tmp->next == NULL){
            free_node(tmp);
            *head = NULL;
             return;
        } else {
            struct Node* next_node = tmp->next;
            free_node(tmp);
            *head = next_node;
            return;
        }
    }

    struct Node* prev = tmp;

    while (tmp != NULL){
        if (strcmp(tmp->key, key) != 0){
            prev = tmp;
            tmp = tmp->next;
            continue;
        }
        //tmp is the node we are searching for
        prev->next = tmp->next;
        free_node(tmp);
        return;
    }
}




int main(){
    struct Node* head = NULL;
    int data = 10;
    void* p_data = &data;
    insert_at_beginning(&head, p_data, sizeof(int), "0");
    data = 20;
    insert_at_beginning(&head, p_data, sizeof(int), "1");
    data = 30;
    insert_at_beginning(&head, p_data, sizeof(int), "2");

    data = 7;
    insert_at_end(&head, p_data, sizeof(int), "3");
    data = 3;
    insert_at_end(&head, p_data, sizeof(int), "4");

    // delete_by_key(&head, "3");
    delete_all_list(&head);

    print_list(head, 'd');
}

