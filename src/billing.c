#include <stdio.h>
#include <string.h>
#include "../include/billing.h"


void addItem(struct Item items[], int *count) {
if (*count >= MAX) {
printf("Item limit reached!\n");
return;
}


printf("Enter item name: ");
scanf("%s", items[*count].name);


printf("Enter price: ");
scanf("%f", &items[*count].price);


printf("Enter quantity: ");
scanf("%d", &items[*count].quantity);


(*count)++;
printf("Item added successfully!\n");
}




void displayBill(struct Item items[], int count) {
float total = 0;


printf("\n---- BILL DETAILS ----\n");
printf("%-20s %-10s %-10s %-10s\n", "Item", "Price", "Qty", "Amount");


for (int i = 0; i < count; i++) {
float amount = items[i].price * items[i].quantity;
total += amount;


printf("%-20s %-10.2f %-10d %-10.2f\n",
items[i].name, items[i].price, items[i].quantity, amount);
}


printf("-----------------------------\n");
printf("Total Amount: ₹ %.2f\n", total);
}