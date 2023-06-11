#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void print_readable_size(unsigned long size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double readable_size = (double)size;

    while (readable_size >= 1024 && i < 4) {
        readable_size /= 1024;
        i++;
    }

    printf("%.2f %s", readable_size, units[i]);
}

int main(int argc, char* argv[]) {
    int use_human_readable = 0;

    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        use_human_readable = 1;
    }

    struct statvfs buf;

    if (statvfs(".", &buf) == -1) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    unsigned long total_blocks = buf.f_blocks;
    unsigned long free_blocks = buf.f_bfree;
    unsigned long available_blocks = buf.f_bavail;
    unsigned long block_size = buf.f_frsize;

    unsigned long total_size = total_blocks * block_size;
    unsigned long free_size = free_blocks * block_size;
    unsigned long available_size = available_blocks * block_size;

    printf("Filesystem Size: ");
    if (use_human_readable) {
        print_readable_size(total_size);
    } else {
        printf("%lu", total_size);
    }
    printf("\n");

    printf("Free Space: ");
    if (use_human_readable) {
        print_readable_size(free_size);
    } else {
        printf("%lu", free_size);
    }
    printf("\n");

    printf("Available Space: ");
    if (use_human_readable) {
        print_readable_size(available_size);
    } else {
        printf("%lu", available_size);
    }
    printf("\n");

    return 0;
}


