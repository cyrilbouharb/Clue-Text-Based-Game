#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

  struct Item{
   char* name;
   struct Item *next;
  };
  

 struct Item *item(char* name, struct Item *next);

 struct Item *add_item(struct Item *listPtr, struct Item *item);

 struct Item *drop_item(struct Item *listPtr, char *name);

 bool has_item(struct Item *listPtr, char* name);

 void printItems(struct Item *listPtr);

 char* itemName(struct Item *item);

 struct Item *getNextItem(struct Item *item);

