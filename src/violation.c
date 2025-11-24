#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "violation.h"
#include "vehicle.h"

static const char *VIOL_FILE = "violations.txt";

static void trimnl(char *s) { size_t n = strlen(s); if (n && s[n-1]=='\n') s[n-1]=0; }

static int next_id(void) {
    FILE *f = fopen(VIOL_FILE, "r");
    if (!f) return 1;
    int id = 0;
    while (!feof(f)) {
        int x = 0;
        if (fscanf(f, "%d", &x)==1) if (x > id) id = x;
        /* skip to next line */
        int c; while ((c=fgetc(f)) != EOF && c != '\n');
    }
    fclose(f);
    return id + 1;
}

int record_violation(void) {
    Violation v;
    printf("Enter reg no: ");
    if (!fgets(v.reg_no, sizeof(v.reg_no), stdin)) return 0; trimnl(v.reg_no);
    if (strlen(v.reg_no)==0) { printf("Empty\n"); return 0; }

    /* simple check: assume registered if vehicles.txt has reg */
    FILE *vf = fopen("vehicles.txt", "r");
    int found = 0;
    if (vf) {
        char line[MAX_LINE];
        while (fgets(line, sizeof(line), vf)) if (strstr(line, v.reg_no)) { found = 1; break; }
        fclose(vf);
    }
    if (!found) { printf("Vehicle not registered\n"); return 0; }

    printf("Violation type: "); if (!fgets(v.vtype, sizeof(v.vtype), stdin)) return 0; trimnl(v.vtype);
    printf("Date: "); if (!fgets(v.date, sizeof(v.date), stdin)) return 0; trimnl(v.date);
    v.fine = 500; v.paid = 0; v.id = next_id();
    FILE *f = fopen(VIOL_FILE, "a"); if (!f) { perror("fopen"); return 0; }
    fprintf(f, "%d,%s,%s,%s,%d,%d\n", v.id, v.reg_no, v.vtype, v.date, v.fine, v.paid);
    fclose(f);
    printf("Recorded id=%d fine=%d\n", v.id, v.fine);
    return 1;
}

int list_violations(void) {
    FILE *f = fopen(VIOL_FILE, "r"); if (!f) { printf("No viols\n"); return 0; }
    char line[MAX_LINE];
    printf("ID,Reg,Type,Date,Fine,Paid\n");
    while (fgets(line, sizeof(line), f)) {
        trimnl(line);
        printf("%s\n", line);
    }
    fclose(f);
    return 1;
}
