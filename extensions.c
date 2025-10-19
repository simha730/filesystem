#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    char dir_path[256];
    printf("Enter directory path: ");
    scanf("%s", dir_path);

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return 1;
    }

    struct dirent *entry;
    int txt_count = 0, c_count = 0, log_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it is a regular file
            char *ext = strrchr(entry->d_name, '.');  // Find last '.'
            if (ext != NULL) {
                if (strcmp(ext, ".txt") == 0)
                    txt_count++;
                else if (strcmp(ext, ".c") == 0)
                    c_count++;
                else if (strcmp(ext, ".log") == 0)
                    log_count++;
            }
        }
    }

    closedir(dir);

    printf("\nFile counts in directory %s:\n", dir_path);
    printf(".txt files: %d\n", txt_count);
    printf(".c files: %d\n", c_count);
    printf(".log files: %d\n", log_count);

    return 0;
}
