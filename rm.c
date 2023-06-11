#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일1> <파일2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        int result = remove(argv[i]);
        if (result == 0) {
            printf("%s 파일이 성공적으로 삭제되었습니다.\n", argv[i]);
        } else {
            perror("파일 삭제 실패");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

