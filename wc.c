#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void count_file_stats(const char* filename, int* line_count, int* word_count, int* char_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int in_word = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        (*char_count)++;

        if (ch == '\n') {
            (*line_count)++;
        }

        if (isspace(ch)) {
            in_word = 0;
        } else {
            if (!in_word) {
                in_word = 1;
                (*word_count)++;
            }
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename> [-m] [-l] [-w]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];

    int print_char_count = 0;
    int print_line_count = 0;
    int print_word_count = 0;

    int i;
    for (i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-m") == 0) {
            print_char_count = 1;
        } else if (strcmp(argv[i], "-l") == 0) {
            print_line_count = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            print_word_count = 1;
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    int line_count = 0;
    int word_count = 0;
    int char_count = 0;

    count_file_stats(filename, &line_count, &word_count, &char_count);

    if (print_char_count) {
        printf("Characters: %d\n", char_count);
    }
    if (print_line_count) {
        printf("Lines: %d\n", line_count);
    }
    if (print_word_count) {
        printf("Words: %d\n", word_count);
    }

    if (!print_char_count && !print_line_count && !print_word_count) {
        printf("Lines: %d\n", line_count);
        printf("Words: %d\n", word_count);
        printf("Characters: %d\n", char_count);
    }

    return 0;
}



