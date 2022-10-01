#ifndef LINKED_LIST_   /* Include guard */
#define LINKED_LIST_

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

#endif // LINKED_LIST_