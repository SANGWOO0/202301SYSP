#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *ent;
    
    dir = opendir(".");
    if (dir == NULL) {
        perror("디렉토리를 열 수 없습니다.");
        return EXIT_FAILURE;
    }
    
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }
    
    closedir(dir);
    
    return EXIT_SUCCESS;
}
