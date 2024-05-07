#include "repository.h"
#include "dorm.h"
#include "student.h"
#include "gender.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include the header file for exit()
#include <errno.h> // Include the header file for stderr

void parse_file_std(FILE *student, struct student_t *students, unsigned int *num_students, unsigned int *student_capacity) {
    *num_students = 0;
    while (fscanf(student, "%s %s %d %s\n", students[*num_students].id, students[*num_students].name, &students[*num_students].year, students[*num_students].gender) != EOF) {
        (*num_students)++;
        if (*num_students >= *student_capacity) {
            *student_capacity *= 2;
            students = realloc(students, *student_capacity * sizeof(struct student_t));
            if (students == NULL) {
                fprintf(stderr, "Failed to reallocate memory for students\n");
                exit(1);
            }
        }
    }
}

void parse_file_drm(FILE *dorm, struct dorm_t *dorms, unsigned int *num_dorms, unsigned int *dorm_capacity) {
    *num_dorms = 0;
    char gender_str[10];
    while (fscanf(dorm, "%s %d %s\n", dorms[*num_dorms].name, &dorms[*num_dorms].capacity, gender_str) != EOF) {
        if (strcmp(gender_str, "male") == 0) {
            dorms[*num_dorms].gender = GENDER_MALE;
        } else {
            dorms[*num_dorms].gender = GENDER_FEMALE;
        }
        (*num_dorms)++;
        if (*num_dorms >= *dorm_capacity) {
            *dorm_capacity *= 2;
            dorms = realloc(dorms, *dorm_capacity * sizeof(struct dorm_t));
            if (dorms == NULL) {
                fprintf(stderr, "Failed to reallocate memory for dorms\n");
                exit(1);
            }
        }
    }
}