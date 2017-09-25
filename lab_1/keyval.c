#include <stdlib.h>
#include "keyval.h"

keyval *keyval_new(const char *key, void *value) {
    keyval *out = malloc(sizeof(keyval));
    *out = (keyval) {.key=key, .value=value};
    return out;
}

void keyval_free(keyval *in){
    free(in);
}