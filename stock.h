#ifndef STOCK_H
#define STOCK_H

#include "stock.cpp"

//void bubblesort(int ID[],char name[][100],int quantity[],int price[],int total[],int n);
void bubblesort(int *ID, char ***name, int *quantity, int *price, int *total, int n);

void newstock();

void updatedstock();

void viewstock();

void removingstock();

void searchstock();


#endif
