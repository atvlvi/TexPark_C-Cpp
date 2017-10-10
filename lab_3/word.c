#include <string.h>
#include <stdlib.h>
#include "word.h"

word* new_word(char* in) {
    word* out = malloc(sizeof(word));
    if (!out) return NULL;
    out->value = malloc(strlen(in));
    if (!out->value) {
        free(out);
        return NULL;
    }
    out->count = 1;
    strcpy(out->value, in);
    return out;
}

void free_word(word *in) {
    free(in->value);
    free(in);
}