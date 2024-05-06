#include "repository.h"
#include "dorm.h"
#include "student.h"
#include "gender.h"
#include <stdio.h>

void repository_dorms(struct dorm_t *_dorms, int _num_dorms) {
    char buff[255];
    char text[255];
    FILE *fp;

    fp = fopen("dorms.txt", "w");
    fp = fopen("students.txt", "w");

    while(fgets(buff, sizeof(buff),fp)){
        sscanf(buff, "%s", text);
    }
    fclose(fp);
}
