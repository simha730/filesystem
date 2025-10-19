#include <stdio.h>
#include <stdlib.h>

#define NUM_FILES 3
#define NUM_LINES 5

int main() {
    char *filenames[NUM_FILES] = {"file1.txt", "file2.txt", "file3.txt"};
    char buffer[256];

    // 1️⃣ Create files and write 5 lines to each
    for (int i = 0; i < NUM_FILES; i++) {
        FILE *fp = fopen(filenames[i], "w");
        if (fp == NULL) {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }

        for (int j = 1; j <= NUM_LINES; j++) {
            fprintf(fp, "This is line %d in %s\n", j, filenames[i]);
        }

        fclose(fp);
        printf("Written %d lines to %s\n", NUM_LINES, filenames[i]);
    }

    printf("\n");

    // 2️⃣ Read and print contents of all files
    for (int i = 0; i < NUM_FILES; i++) {
        FILE *fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        printf("Contents of %s:\n", filenames[i]);
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        printf("\n");

        fclose(fp);
    }

    return 0;
}
