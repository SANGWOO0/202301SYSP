#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s [옵션] 디렉토리...\n", argv[0]);
        return 1;
    }

    int verbose = 0;
    int directory_index = 1;

    if (argc >= 3 && strcmp(argv[1], "-v") == 0) {
        verbose = 1;
        directory_index = 2;
    }

    for (int i = directory_index; i < argc; i++) {
        const char *dir = argv[i];

        if (mkdir(dir, 0777) != 0) {
            printf("디렉토리 생성에 실패했습니다: %s\n", dir);
            return 1;
        }

        if (verbose) {
            printf("디렉토리 생성됨: %s\n", dir);
        }
    }

    return 0;
}

