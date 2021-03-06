#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "word.h"

#define MAXLEN 64

void sort_list(node *list);
int insert(node *list, char *in);
void print_list(node *list);

void destruct(void *value) {
    free_word(value);
}

int main(int argc, char *argv[]) {
    switch (argc) {
        case 1:
            fprintf(stderr, "missing 1 required positional arguments: 'file name'\n");
            return -1;
        case 2:
            break;
        default:
            fprintf(stderr, "takes 1 positional arguments but %i were given\n", argc - 1);
            return -1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        fprintf(stderr, "No such file or directory: '%s'\n", argv[1]);
        return -1;
    }

    char buf[MAXLEN];
    char string[MAXLEN];
    char *link = string;
    char *max_link = string + MAXLEN - 1;
    node *list = new_node(NULL, destruct);
    size_t len = 0;

    do {
        len = fread(buf, sizeof(char), MAXLEN, fin);
        for (int i = 0; i < len; i++) {
            if (isspace(buf[i]) || ispunct(buf[i])) {
                if (link == string)
                    continue;
                *link = '\0';
                if (!insert(list, string)) {
                    fprintf(stderr, "memory allocation error\n");
                    return -1;
                }
                link = string;
            } else if (link < max_link) {
                *link = buf[i];
                link++;
            } else {
                fprintf(stderr, "word lenght more than MAXLEN\n");
            }
        }
    } while(len == MAXLEN);

    if (errno)
        fprintf(stderr, "%s", strerror(errno));

    sort_list(list);
    print_list(list);

    free_list(list);
    fclose(fin);

    return 0;
}

int insert(node *list, char *in) {
    if (!list->value) {
        list->value = new_word(in);
        if (!list->value)
            return 0;
        list->next = new_node(NULL, destruct);
        if (!list->next)
            return 0;
        return 1;
    }
    if (!strcmp(((word *) list->value)->value, in)) {
        ((word *) list->value)->count++;
        return 1;
    }
    insert(list->next, in);
    return 1;
}

void print_list(node *list) {
    if (!list->value)
        return;
    printf("%i: %s \n", ((word *) list->value)->count, ((word *) list->value)->value);
    print_list(list->next);
}

int sort_list_body(node *list) {
    if (!((word *)list->next)->value)
        return 0;
    node *next = list->next;
    void *buf = NULL;
    if (((word *)list->value)->count < ((word *)next->value)->count) {
        buf = list->value;
        list->value = next->value;
        next->value = buf;
        return 1 + sort_list_body(next);
    }
    return sort_list_body(next);
}

void sort_list(node *list) {
    while (sort_list_body(list));
}
// key key key key key key key key