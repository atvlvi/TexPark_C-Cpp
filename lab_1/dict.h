#ifndef DICT
#define DICT

#include "keyval.h"

extern void *dict_not_found;
typedef struct dict {
    keyval **pairs;
    size_t length;
    size_t sqrt;
} dict;

dict *dict_new(void);
void dict_free(dict *in);
void dict_add(dict *in, const char *key, void *value);
void *dict_find(dict const *in, char const *key);

#endif