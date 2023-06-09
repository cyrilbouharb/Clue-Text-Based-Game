#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h" 
#include <time.h>

// // goal: creates an Item struct given the name and the next pointer of type stuct item so we
// can be able to create a Linked List of items
// param name: represents the name of the item making it easy to distinguish
// return: an Item struct

 struct Item *item(char* name, struct Item *next) {
  struct Item *newItem = (struct Item *) malloc(sizeof(struct Item));
  if ( newItem == NULL) 
      return NULL;
  newItem->name = name;
  newItem->next = NULL;
   return newItem;
 }
 // goal: gets the name from an Item struct
// param struct Item: pointer that point to a struct representing an Item
// return: a char pointer to the string representing the name of item
//
 char* itemName(struct Item *item) {
   return item->name;
 }
 
 // goal: gets the next item of an Item struct
// param struct Item: pointer that point to a struct representing an Item
// return: an Item struct representing the next item
//
 
struct Item *getNextItem(struct Item *item) {
   return item->next;
}
// goal: adds an item to the itemList 
// param struct Item *listPtr: pointer that point to a struct representing a list of items
// param struct Item *item: pointer that point to a struct representing an Item
// return: a pointer to the list of items. Type struct Item *
//
 struct Item *add_item(struct Item *listPtr, struct Item *item) {
       if (listPtr == NULL) {
          listPtr = item;
          printf("Item has been added here! \n");
       } else{
       listPtr->next = item;
       printf("Item has been added!\n");
       }
       return listPtr;
  }
// goal: checks to see if this list has this specific item
// param struct Item *listPtr: pointer that point to a struct representing a list of items
// param char* name: pointer to the name of the item we're searching for
// return: a boolean either True or False depending if the item is in the list
//
 bool has_item(struct Item *listPtr, char* name) {
       struct Item *curr = listPtr;
       while (curr != NULL) {
         if (strcmp(curr->name, name) == 0) {
           return true;
         }
        curr = curr->next;
       }
       return false;
}
// goal: prints all the items in the itemlist
// param struct Item *listPtr: pointer that point to a struct representing a list of items
// return: type void. We aren't returning anything
//
 void printItems(struct Item *listPtr) {
    struct Item *curr = listPtr;
    printf("This is the item list:\n");
    if (curr == NULL) printf("There are no items!\n");
    while (curr != NULL) {
      printf("%s\n",curr->name);
      curr = curr->next;
   }
 }

// goal: removes an item from the itemList 
// param struct Item *listPtr: pointer that point to a struct representing a list of items
// param char* name: pointer to the name of the item we're removing
// return: a pointer to the item we removed of type struct Item *
//
 struct Item *drop_item(struct Item *listPtr, char *name) {
    struct Item *curr = listPtr;
    struct Item *prev;
    //in case it's at the head of the Linked List
    if(listPtr != NULL && strcmp(curr->name,name) == 0 ) {
       listPtr = curr->next;
       printf("Item Dropped. \n");
       return curr;
    }
     // Find the key to be deleted
   while (curr != NULL && strcmp(curr->name,name) != 0) {
   prev = curr;
   curr = curr->next;
  }
  // If the key is not present
   if (curr == NULL) return NULL;
   else {
    // Remove the node
   prev->next = curr->next;
   printf("Item Dropped. \n");
   return curr;

   }
}

















        
