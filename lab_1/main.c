#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include "dict.h"

#define MAXLEN 64

int check(int argc, int *n, const char *argv[]);
int is_zero(const char *argv);

int main(int argc, char* argv[]) {
	int *count = NULL;
	int n = 0;
	char c = 0;
	char buf[MAXLEN];
	char *buf_link = buf;
	dict *dict = dict_new();
	if (check(argc, &n, (const char**)argv)) {
		FILE *fin = fopen(argv[2], "r");
		if (fin) {
			while ((c = (char)getc(fin)) !=EOF) {
				if (ispunct(c) || isspace(c)) {
					if (buf_link == buf)
						continue;
					*buf_link = '\0';
					count = dict_find(dict, buf);
					if (count == dict_not_found) {
						count = (int *) malloc(sizeof(int));
						if (!count) {
							fprintf(stderr, "Memory allocation error");
							return 0;
						}
						*count = 1;
						dict_add(dict, strcpy(malloc(strlen(buf)), buf), count);
					}
					else {
						(*count)++;
					}
					buf_link = buf;
				} else if (buf_link - buf < 63) {
					*buf_link = c;
					buf_link++;
				}
			}
			fclose(fin);
            for (int i = 0; i < dict->length; i++)
                if (dict->pairs[i])
                    if (*(int *)dict->pairs[i]->value > n)
                        printf("%s: %i\n", dict->pairs[i]->key, *(int *)dict->pairs[i]->value);
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