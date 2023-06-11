#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

int main() {
    char path[MAX_PATH_LENGTH];

    if (getcwd(path, sizeof(path)) != NULL) {
        printf("현재 작업 디렉토리: %s\n", path);
    } else {
        perror("작업 디렉토리를 가져올 수 없습니다.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

