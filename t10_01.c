// 12S23009 - Dina Marlina Siagian
// 12S23047 - Jennifer Hopenes Sihotang

#include <stdio.h>
#include <stdlib.h>

void backup_repository(const char *filename, const char *backup_filename) {
    FILE *repository_file = fopen(filename, "r");
    if (repository_file == NULL) {
        fprintf(stderr, "Failed to open repository file\n");
        exit(1);
    }

    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        fprintf(stderr, "Failed to create backup file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), repository_file) != NULL) {
        fputs(line, backup_file);
    }

    fclose(repository_file);
    fclose(backup_file);

    printf("Backup of %s created successfully.\n", filename);
}

int main() {
    backup_repository("./storage/dorm-repository.txt", "./storage/backup_dorm-repository.txt");
    backup_repository("./storage/student-repository.txt", "./storage/backup_student-repository.txt");
    return 0;
}
