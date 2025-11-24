/*
  Simple main menu written in a beginner style.
  Uses fgets + atoi to avoid scanf pitfalls.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehicle.h"
#include "violation.h"
#include "reports.h"

static void wait_enter(void) {
    char buf[8];
    printf("\nPress Enter to continue...");
    fgets(buf, sizeof(buf), stdin);
}

int main(void) {
    char buf[32];
    while (1) {
        printf("\n=== Simple Traffic System (student) ===\n");
        printf("1) Vehicle: add/list/delete\n");
        printf("2) Record Violation\n");
        printf("3) List Violations\n");
        printf("4) Mark Paid\n");
        printf("5) Reports\n");
        printf("0) Exit\n");
        printf("Choose: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        int choice = atoi(buf);
        if (choice == 0) { printf("Bye\n"); break; }
        if (choice == 1) {
            printf("1-Add 2-List 3-Delete: ");
            if (!fgets(buf, sizeof(buf), stdin)) break;
            int sub = atoi(buf);
            if (sub == 1) add_vehicle();
            else if (sub == 2) list_vehicles();
            else if (sub == 3) delete_vehicle();
            else printf("Unknown\n");
            wait_enter();
            continue;
        }
        if (choice == 2) { record_violation(); wait_enter(); continue; }
        if (choice == 3) { list_violations(); wait_enter(); continue; }
        if (choice == 4) { mark_violation_paid(); wait_enter(); continue; }
        if (choice == 5) { daily_collection_report(); wait_enter(); continue; }
        printf("Invalid option\n");
    }
    return 0;
}
