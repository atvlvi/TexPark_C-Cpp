#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "dict.h"

int check(int argc, int *n, const char* argv[]);
int is_zero(char *argv);

int main(int argc, char* argv[]) {
	int n = 0;
	if (check(argc, &n, argv)) {
		printf("n = %i", n);

	}
}

int dict_test(){
	int zero = 0;
	float one = 1.0;
	char two[] = "two";
	dictionary *d = dictionary_new();
	dictionary_add(d, "an int", &zero);
	dictionary_add(d, "а float", &one);
	dictionary_add(d, "а string", &two);
	printf("Я сохранил целое: %i\n",
		   *(int *) dictionary_find(d, "an int"));
	printf("Coxpaнeннaя строка: %s\n", (char *) dictionary_find(d, "а string"));
	dictionary_free(d);
}

int check(int argc, int *n, const char* argv[]) {
	switch(argc) {
		case 1:
			fprintf(stderr, "missing 2 required positional arguments: 'N' and 'file name'\n");
			return 0;
		case 2:
			fprintf(stderr, "missing 1 required positional argument: 'file name\n'");
			return 0;
		case 3:
			if (is_zero(argv[1])) {
				*n = 0;
				return 1;
			}
			else {
				*n = strtol(argv[1], NULL, 10);
				if (*n)
					return 1;
				else {
					perror(errno);
					return 0;
				}
			}
		default:
			fprintf(stderr, "takes 2 positional arguments but %i were given\n", argc - 1);
			return 0;
	}
	//return 0;
}

int is_zero(char *argv) {
	for (;;argv++) {
		if (*argv == '\0')
			return 1;
		if (*argv != '0')
			return 0;
	}
}