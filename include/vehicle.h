
#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX_REG 32
#define MAX_NAME 80
#define MAX_TYPE 32
#define MAX_CONTACT 32
#define MAX_LINE 256

typedef struct {
    char reg_no[MAX_REG];
    char owner[MAX_NAME];
    char vtype[MAX_TYPE];
    char contact[MAX_CONTACT];
} Vehicle;

/* simple functions for vehicle management */
int add_vehicle(void);
int list_vehicles(void);
int delete_vehicle(void);

#endif /* VEHICLE_H */

