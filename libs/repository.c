#include "repository.h"
#include "dorm.h"
#include "student.h"
#include "gender.h"
#include <stdio.h>
#include <stdlib.h> // Include the header file for exit()
#include <errno.h> // Include the header file for stderr

void repository_dorms(struct dorm_t *_dorms, int _num_dorms) {
    FILE *fp;

    fp = fopen("dorms.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open dorms.txt for writing\n");
        exit(1);
    }

    for (int i = 0; i < _num_dorms; i++) {
        fprintf(fp, "%s %d %s\n", _dorms[i].name, _dorms[i].capacity, _dorms[i].gender == GENDER_MALE ? "male" : "female");
    }

    fclose(fp);
}
