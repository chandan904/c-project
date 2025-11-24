#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "penalty.h"

static const char *VIOL_FILE = "violations.txt";

static void trimnl(char *s) { size_t n = strlen(s); if (n && s[n-1]=='\n') s[n-1]=0; }

int mark_violation_paid(void) {
    char buf[32];
    printf("Enter violation id: ");
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    int id = atoi(buf);
    FILE *f = fopen(VIOL_FILE, "r");
    if (!f) { printf("No file\n"); return 0; }
    FILE *tmp = fopen("violations_tmp.txt", "w");
    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), f)) {
        char copy[256]; strcpy(copy, line);
        int vid; char reg[64], type[64], date[32]; int fine, paid;
        if (sscanf(copy, "%d,%63[^,],%63[^,],%31[^,],%d,%d", &vid, reg, type, date, &fine, &paid) == 6) {
            if (vid == id) {
                if (paid) {
                    fputs(line, tmp);
                    printf("Already paid\n");
                } else {
                    fprintf(tmp, "%d,%s,%s,%s,%d,1\n", vid, reg, type, date, fine);
                    printf("Marked paid amount=%d\n", fine);
                    found = 1;
                }
            } else fputs(line, tmp);
        } else fputs(line, tmp);
    }
    fclose(f); fclose(tmp);
    if (!found) { remove("violations_tmp.txt"); printf("ID not found\n"); return 0; }
    rename("violations_tmp.txt", VIOL_FILE);
    return 1;
}
