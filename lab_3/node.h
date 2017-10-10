#ifndef LAB_3_NODE_H
#define LAB_3_NODE_H

typedef struct node node;
struct node {
    void *value;
    node *next;
    void (*destruct)(void *value);
};

void free_list(node *in);
void free_node(node *in);
node* new_node(void* value, void (*destruct)(void *value));
void node_swap(node *in);

#endif //LAB_3_NODE_H
