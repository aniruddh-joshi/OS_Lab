#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to simulate cp command
void my_cp(char *source, char *destination) {
    FILE *sourceFile, *destFile;
    char ch;

    sourceFile = fopen(source, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return;
    }

    destFile = fopen(destination, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully!\n");

    fclose(sourceFile);
    fclose(destFile);
}

// Function to simulate ls command
void my_ls() {
    system("ls");
}

// Function to simulate grep command
void my_grep(char *pattern, char *filename) {
    FILE *file;
    char line[100];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [options]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "cp") == 0) {
        if (argc != 4) {
            printf("Usage: %s cp source destination\n", argv[0]);
            return 1;
        }
        my_cp(argv[2], argv[3]);
    } else if (strcmp(argv[1], "ls") == 0) {
        my_ls();
    } else if (strcmp(argv[1], "grep") == 0) {
        if (argc != 4) {
            printf("Usage: %s grep pattern filename\n", argv[0]);
            return 1;
        }
        my_grep(argv[2], argv[3]);
    } else {
        printf("Unsupported command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}

