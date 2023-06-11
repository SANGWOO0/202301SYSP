#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <파일 경로>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return EXIT_SUCCESS;
}

