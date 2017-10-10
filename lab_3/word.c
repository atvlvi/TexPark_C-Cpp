#include <string.h>
#include <stdlib.h>
#include "word.h"

word* new_word(char* in) {
    word* out = malloc(sizeof(word));
    if (!out) return NULL;
    size_t len = strlen(in)+1;
    out->value = malloc(len);
    if (!out->value) {
        free(out);
        return NULL;
    }
    out->count = 1;
    strncpy(out->value, in, len);
    return out;
}

void free_word(word *in) {
    free(in->value);
    free(in);
}