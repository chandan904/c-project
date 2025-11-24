/* very small reports for beginner */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reports.h"

int daily_collection_report(void) {
    /* read violations file and sum paid fines */
    FILE *f = fopen("violations.txt", "r");
    if (!f) { printf("No data\n"); return 0; }
    int total = 0;
    while (!feof(f)) {
        int id, fine, paid;
        char reg[64], type[64], date[32];
        if (fscanf(f, "%d,%63[^,],%63[^,],%31[^,],%d,%d\n", &id, reg, type, date, &fine, &paid) == 6) {
            if (paid) total += fine;
        } else { /* skip line */ char tmp[256]; if (!fgets(tmp, sizeof(tmp), f)) break; }
    }
    fclose(f);
    printf("Total collected = %d\n", total);
    return 1;
}

int pending_fines_report(void) {
    FILE *f = fopen("violations.txt", "r"); if (!f) { printf("No data\n"); return 0; }
    printf("Pending: id,reg,fine\n");
    while (!feof(f)) {
        int id, fine, paid;
        char reg[64], type[64], date[32];
        if (fscanf(f, "%d,%63[^,],%63[^,],%31[^,],%d,%d\n", &id, reg, type, date, &fine, &paid) == 6) {
            if (!paid) printf("%d,%s,%d\n", id, reg, fine);
        } else { char tmp[256]; if (!fgets(tmp, sizeof(tmp), f)) break; }
    }
    fclose(f);
    return 1;
}
