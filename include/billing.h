#ifndef BILLING_H
#define BILLING_H


#define MAX 50


struct Item {
char name[30];
float price;
int quantity;
};


void addItem(struct Item items[], int *count);
void displayBill(struct Item items[], int count);


#endif