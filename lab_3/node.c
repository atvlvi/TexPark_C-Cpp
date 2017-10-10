#include <stdlib.h>
#include "node.h"

node* new_node(void* value, void (*destruct)(void *value)) {
    node *out = malloc(sizeof(node));
    if (!out) return NULL;
    out->destruct = destruct;
    out->next = NULL;
    out->value = value;
    return out;
}

void free_node(node *in) {
    in->destruct(in->value);
    free(in->value);
    free(in);
}

void free_list(node *in) {
    if (in->value != NULL) {
        free_list(in->next);
        free_node(in);
    }
}