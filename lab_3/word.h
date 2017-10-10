#ifndef LAB_3_WORD_H
#define LAB_3_WORD_H

typedef struct word {
    int count;
    char *value;
} word;

word* new_word(char* in);
void free_word(word *in);

#endif //LAB_3_WORD_H