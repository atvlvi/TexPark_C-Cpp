#ifndef KEYVAL
#define KEYVAL

typedef struct keyval {
    const char *key;
    void *value;
} keyval;

keyval *keyval_new(const char *key, void *value);
void keyval_free(keyval *in);

#endif