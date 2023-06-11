#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define DEFAULT_LINES 10

void print_head(const char* filename, int lines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;

    while (line_count < lines && fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
        line_count++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    int lines = DEFAULT_LINES;
    const char* filename = NULL;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            lines = atoi(argv[i + 1]);
            i++;  // Skip the next argument since it has been processed as the line count
        } else {
            filename = argv[i];
        }
    }

    if (filename == NULL) {
        printf("Usage: %s [-n lines] filename\n", argv[0]);
        return 1;
    }

    print_head(filename, lines);

    return 0;
}


