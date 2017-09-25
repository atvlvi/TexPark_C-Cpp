#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dict.h"

#define MIN_DICT_LEN 15

void *dict_not_found;

static unsigned long hash(const char *str) {
    unsigned long hash = 0;
    for(; *str; str++)
        hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;
    return hash;
}

static unsigned long dict_hash(const dict *in, const char *str) {
    return hash(str) % (unsigned int)in->length;
}

dict *dict_new_body(size_t len) {
    dict *out = malloc(sizeof(dict));
    *out = (dict) {.pairs = calloc(len, sizeof(keyval *)), .length = len, .sqrt = (size_t)(int)sqrt(len)};
    return out;
}

dict *dict_new(void){
    static int dnf;
    if(!dict_not_found)
        dict_not_found = &dnf;
    return dict_new_body(MIN_DICT_LEN);
}

void dict_expand(dict *in) {
    keyval** pairs = in->pairs;
    dict *out = dict_new_body(in->length * 2 - 1);
    for (int i = 0; i < in->length; i++) {
        if (pairs[i])
            dict_add(out, pairs[i]->key, pairs[i]->value);
    }
    dict_free(in);
    *in = *out;
}

void dict_add(dict *in, const char *key, void *value) {
    if (!key) {
        fprintf(stderr, "The key can not be NULL.\n");
        abort();
    }
    keyval** pairs = in->pairs;
    long key_hash = dict_hash(in, key);
    size_t max = (in->length > (key_hash + in->sqrt)) ? key_hash + in->sqrt : in->length;
    for (int i = key_hash; i < max && i; i++) {
        if (!pairs[i]) {
            pairs[i] = keyval_new(key, value);
            return;
        }
        if (strcmp(key, pairs[i]->key) == 0) {
            free(pairs[i]);
            pairs[i] = keyval_new(key, value);
            return;
        }
    }
    dict_expand(in);
    dict_add(in, key, value);
}

void *dict_find(const dict *in, const char *key) {
    long key_hash = dict_hash(in, key);
    keyval** pairs = in->pairs;
    for (int i = key_hash; i < key_hash + in->sqrt; i++) {
        if (!pairs[i]) {
            return dict_not_found;
        }
        if (strcmp(key, pairs[key_hash]->key) == 0) {
            return pairs[key_hash]->value;
        }
    }
    return dict_not_found;
}

void dict_free(dict *in) {
    for (int i = 0; i < in->length; i++)
        keyval_free;
}