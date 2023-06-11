#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void copy_file(const char *source, const char *destination, bool interactive) {
    // 원본 파일 열기
    FILE *source_file = fopen(source, "rb");
    if (source_file == NULL) {
        printf("원본 파일을 열 수 없습니다.\n");
        return;
    }

    // 대상 파일 열기
    FILE *destination_file = fopen(destination, "rb");
    if (destination_file != NULL && interactive) {
        // 대상 파일이 이미 존재하고 -i 옵션이 주어진 경우 덮어쓸지 물어봄
        printf("%s 파일이 이미 존재합니다. 덮어쓰시겠습니까? (y/n) ", destination);
        char response;
        scanf(" %c", &response);

        if (response != 'y' && response != 'Y') {
            // 덮어쓰지 않을 경우 작업 취소
            printf("복사 작업이 취소되었습니다.\n");
            fclose(source_file);
            fclose(destination_file);
            return;
        }
    }

    // 대상 파일 열기 (쓰기 모드)
    destination_file = fopen(destination, "wb");
    if (destination_file == NULL) {
        printf("대상 파일을 열 수 없습니다.\n");
        fclose(source_file);
        return;
    }

    // 원본 파일의 내용을 대상 파일로 복사
    int ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    // 파일 닫기
    fclose(source_file);
    fclose(destination_file);

    printf("파일이 복사되었습니다.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s [옵션] 원본파일 대상파일\n", argv[0]);
        return 1;
    }

    bool interactive = false;
    int source_index = 1;
    if (argc >= 4 && strcmp(argv[1], "-i") == 0) {
        interactive = true;
        source_index = 2;
    }

    const char *source = argv[source_index];
    const char *destination = argv[source_index + 1];

    copy_file(source, destination, interactive);

    return 0;
}

