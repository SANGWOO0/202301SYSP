#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define DEFAULT_LINES 10

void print_tail(const char* filename, int lines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    // Determine the total number of lines in the file
    int total_lines = 0;
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        total_lines++;
    }

    // Calculate the starting line number to print
    int start_line = total_lines - lines;
    if (start_line < 0) {
        start_line = 0;
    }

    // Move to the starting line in the file
    fseek(file, 0, SEEK_SET);
    int current_line = 0;
    while (current_line < start_line && fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        current_line++;
    }

    // Print the lines from the starting line
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
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

    print_tail(filename, lines);

    return 0;
}

