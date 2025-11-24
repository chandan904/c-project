
#ifndef VIOLATION_H
#define VIOLATION_H

#include "vehicle.h"

#define MAX_VIOL_TYPE 64
#define MAX_DATE 24

typedef struct {
    int id;
    char reg_no[MAX_REG];
    char vtype[MAX_VIOL_TYPE];
    char date[MAX_DATE]; /* simple date string */
    int fine;
    int paid; /* 0 = unpaid, 1 = paid */
} Violation;

/* simple functions for violations */
int record_violation(void);
int list_violations(void);

#endif /* VIOLATION_H */



