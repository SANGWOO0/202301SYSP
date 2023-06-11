#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s [옵션] 원본 대상\n", argv[0]);
        return 1;
    }

    int symbolic_link = 0;
    int source_index = 1;

    if (argc >= 4 && strcmp(argv[1], "-s") == 0) {
        symbolic_link = 1;
        source_index = 2;
    }

    const char *source = argv[source_index];
    const char *destination = argv[source_index + 1];

    if (symbolic_link) {
        if (symlink(source, destination) != 0) {
            printf("심볼릭 링크 생성에 실패했습니다.\n");
            return 1;
        }
        printf("심볼릭 링크가 생성되었습니다.\n");
    } else {
        if (link(source, destination) != 0) {
            printf("하드 링크 생성에 실패했습니다.\n");
            return 1;
        }
        printf("하드 링크가 생성되었습니다.\n");
    }

    return 0;
}

