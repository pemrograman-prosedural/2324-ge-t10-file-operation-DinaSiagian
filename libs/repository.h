#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"
#include <stdio.h> // Add this line

void parse_file_std(FILE *student, struct student_t *students, unsigned int *num_students, unsigned int *student_capacity);
void parse_file_drm(FILE *dorm, struct dorm_t *dorms, unsigned int *num_dorms, unsigned int *dorm_capacity);
#endif
