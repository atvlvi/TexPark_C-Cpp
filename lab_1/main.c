#include<stdio.h>
#include"dict.h"
int main() {
	int zero = 0;
	float one = 1.0;
	char two[] = "two";
	dictionary *d = dictionary_new();
	dictionary_add(d, "anint", &zero);
	dictionary_add(d, "аfloat", &one);
	dictionary_add(d, "аstring", &two);
	printf("Ясохранилцелое:%i\n",
		   *(int *) dictionary_find(d, "anint"));
	printf("Coxpaнeннaястрока:%s\n", (char *) dictionary_find(d, "аstring"));
	dictionary_free(d);
}