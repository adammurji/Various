#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
struct item {
    int id;
    char address[SIZE];
    float cost;
    struct item *next;
};//structure, structure

typedef struct item Item;  //give me an alias
typedef struct item *ItemPtr; //for this assignment

void menu(); //With menu's
void printList(ItemPtr); //printinglists
void printFile(ItemPtr); //printing files
ItemPtr makeItem(int); //making information item
ItemPtr removeItem(ItemPtr, int); //destroying an information item
ItemPtr addItem(ItemPtr sPtr, int value); //adding an item in line
void viewItem(ItemPtr sPtr, int value); //show me your delivery
ItemPtr updateItem(ItemPtr sPtr, int value); //make a delivery item anew

