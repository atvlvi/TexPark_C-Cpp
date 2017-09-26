#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include "dict.h"

#define MAXLEN 64

typedef struct word {
    int count;
    int paragraph;
    char flag;
} word;


int check(int argc, int *n, const char *argv[]);
int is_zero(const char *argv);

int main(int argc, char* argv[]) {
	word *loc = NULL;
	int n = 0;
	char c = 0;
	char buf[MAXLEN];
	char *buf_link = buf;
	dict *dict = dict_new();
	if (check(argc, &n, (const char**)argv)) {
		FILE *fin = fopen(argv[2], "r");
		if (fin) {
			while ((c = (char)getc(fin)) !=EOF) {
                if (c != '\n') {
                    if (ispunct(c) || isspace(c)) {
                        if (buf_link == buf)
                            continue;
                        *buf_link = '\0';
                        loc = dict_find(dict, buf);
                        if (loc == dict_not_found) {
                            loc = (word *) malloc(sizeof(word));
                            *loc = (word) {.count = 1, .paragraph = 1, .flag = 1};
                            dict_add(dict, strcpy(malloc(strlen(buf)), buf), loc);
                        } else {
                            if (!loc->flag) {
                                loc->paragraph++;
                                loc->flag = 1;
                            }
                            loc->count++;
                        }
                        buf_link = buf;
                    } else if (buf_link - buf < 63) {
                        *buf_link = c;
                        buf_link++;
                    }
                }
                else
                    for (int i = 0; i < dict->length; i++)
                        if (dict->pairs[i])
                            ((word *)dict->pairs[i]->value)->flag = 0;
			}
			fclose(fin);
            printf("%16s: %16s %16s\n", "слово", "кол. абзацев", "кол. в файле");
            for (int i = 0; i < dict->length; i++)
                if (dict->pairs[i]) {
                    loc = (word *) dict->pairs[i]->value;
                    if (loc->paragraph > n)
                        printf("%16s: %16i %16i\n", dict->pairs[i]->key, loc->paragraph, loc->count);
                }
		}
		else
			fprintf(stderr, "No such file or directory: '%s'\n", argv[2]);
	}
	return 0;

}

int check(int argc, int *n, const char *argv[]) {
	switch(argc) {
		case 1:
			fprintf(stderr, "missing 2 required positional arguments: 'N' and 'file name'\n");
			return 0;
		case 2:
			fprintf(stderr, "missing 1 required positional argument: 'file name'\n");
			return 0;
		case 3:
			if (is_zero((char*)argv[1])) {
				*n = 0;
				return 1;
			}
			else {
				*n = strtol(argv[1], NULL, 10);
				if (errno != 0) {
                    perror("warning: ");
                }
                if (*n == 0 && errno == 0) {
                    fprintf(stderr, "'N' must be integer\n");
                }
				if (*n < 0)
					fprintf(stderr, "'N' must be greater than zero\n");
				return (*n > 0);
			}
		default:
			fprintf(stderr, "takes 2 positional arguments but %i were given\n", argc - 1);
			return 0;
	}
}

int is_zero(const char *argv) {
	for (;;argv++) {
		if (*argv == '\0')
			return 1;
		if (*argv != '0')
			return 0;
	}
}