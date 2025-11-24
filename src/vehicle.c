#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vehicle.h"

static const char *VEH_FILE = "vehicles.txt";

static void trimnl(char *s) {
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[n-1] = '\0';
}

int add_vehicle(void) {
    FILE *f;
    Vehicle v;
    printf("Enter reg no: ");
    if (!fgets(v.reg_no, sizeof(v.reg_no), stdin)) return 0;
    trimnl(v.reg_no);
    if (strlen(v.reg_no) == 0) { printf("Empty reg\n"); return 0; }

    printf("Owner name: ");
    fgets(v.owner, sizeof(v.owner), stdin); trimnl(v.owner);
    printf("Type: ");
    fgets(v.vtype, sizeof(v.vtype), stdin); trimnl(v.vtype);
    printf("Contact: ");
    fgets(v.contact, sizeof(v.contact), stdin); trimnl(v.contact);

    f = fopen(VEH_FILE, "a");
    if (!f) { perror("fopen"); return 0; }
    fprintf(f, "%s,%s,%s,%s\n", v.reg_no, v.owner, v.vtype, v.contact);
    fclose(f);
    printf("Added\n");
    return 1;
}

int list_vehicles(void) {
    FILE *f = fopen(VEH_FILE, "r");
    if (!f) { printf("No vehicles\n"); return 0; }
    char line[MAX_LINE];
    printf("Reg\tOwner\tType\tContact\n");
    while (fgets(line, sizeof(line), f)) {
        trimnl(line);
        printf("%s\n", line);
    }
    fclose(f);
    return 1;
}

int delete_vehicle(void) {
    char reg[MAX_REG];
    printf("Enter reg to delete: ");
    if (!fgets(reg, sizeof(reg), stdin)) return 0;
    trimnl(reg);
    FILE *f = fopen(VEH_FILE, "r");
    if (!f) { printf("No file\n"); return 0; }
    FILE *tmp = fopen("vehicles_tmp.txt", "w");
    char line[MAX_LINE];
    int found = 0;
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, reg) == NULL) fputs(line, tmp);
        else found = 1;
    }
    fclose(f); fclose(tmp);
    if (!found) { remove("vehicles_tmp.txt"); printf("Not found\n"); return 0; }
    rename("vehicles_tmp.txt", VEH_FILE);
    printf("Deleted\n");
    return 1;
}
