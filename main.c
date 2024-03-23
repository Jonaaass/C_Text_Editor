#include <stdio.h>
#include <stdlib.h>

void createFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
        printf("File created: %s\n", filename);
    } else {
        printf("Unable to create file: %s\n", filename);
    }
}

void openFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        printf("Contents of %s:\n", filename);
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

void editFile(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        printf("Enter text. Press Ctrl+D (Unix) or Ctrl+Z (Windows) to save and exit.\n");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            fputs(buffer, file);
        }
        fclose(file);
    } else {
        printf("Unable to open file: %s\n", filename);
    }
}

int main() {
    char filename[256];
    printf("Welcome to Simple Text Editor!\n");
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    // Remove trailing newline
    filename[strcspn(filename, "\n")] = '\0';

    int choice;
    printf("Options:\n");
    printf("1. Create new file\n");
    printf("2. Open existing file\n");
    printf("3. Edit existing file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2:
            openFile(filename);
            break;
        case 3:
            editFile(filename);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
