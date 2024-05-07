// 12S23009 - Dina Marlina Siagian
// 12S23047 - Jennifer Hopenes Sihotang

#include "libs/repository.h" // Change this line
#include "libs/dorm.h"
#include "libs/student.h"
#include "libs/gender.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include the header file for exit()
#include <errno.h>

#define INITIAL_CAPACITY 10

void load_initial_data(struct student_t **students, unsigned int *num_students, unsigned int *student_capacity, struct dorm_t **dorms, unsigned int *num_dorms, unsigned int *dorm_capacity) {
    FILE *student_file = fopen("./storage/student-repository.txt", "r");
    if (student_file == NULL) {
        fprintf(stderr, "Failed to open student-repository.txt for reading\n");
        exit(1);
    }

    FILE *dorm_file = fopen("./storage/dorm-repository.txt", "r");
    if (dorm_file == NULL) {
        fprintf(stderr, "Failed to open dorm-repository.txt for reading\n");
        exit(1);
    }

    *students = malloc(INITIAL_CAPACITY * sizeof(struct student_t));
    *student_capacity = INITIAL_CAPACITY;
    parse_file_std(student_file, *students, num_students, student_capacity);

    *dorms = malloc(INITIAL_CAPACITY * sizeof(struct dorm_t));
    *dorm_capacity = INITIAL_CAPACITY;
    parse_file_drm(dorm_file, *dorms, num_dorms, dorm_capacity);

    printf("Loaded %u students and %u dorms\n", *num_students, *num_dorms);
    
    fclose(student_file);
    fclose(dorm_file);
}

int main() {
    struct student_t *students;
    unsigned int num_students;
    unsigned int student_capacity;

    struct dorm_t *dorms;
    unsigned int num_dorms;
    unsigned int dorm_capacity;

    load_initial_data(&students, &num_students, &student_capacity, &dorms, &num_dorms, &dorm_capacity);

    // The rest of your program goes here

    free(students);
    free(dorms);

    return 0;
}