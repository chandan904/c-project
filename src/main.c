#include <stdio.h>
#include "../include/billing.h"


int main() {
struct Item items[MAX];
int count = 0;
int choice;


while (1) {
printf("\n==== BILLING SYSTEM ====\n");
printf("1. Add Item\n");
printf("2. Display Bill\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);


switch (choice) {
case 1:
addItem(items, &count);
break;


case 2:
displayBill(items, count);
break;


case 3:
printf("Thank you!\n");
return 0;


default:
printf("Invalid choice! Try again.\n");
}
}
}