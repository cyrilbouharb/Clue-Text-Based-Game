#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "items.h"
#include <time.h>
 
 struct Room {
   char* name;
   struct Room *North;
   struct Room *South;
   struct Room *East;
   struct Room *West;
   struct Item *itemList;
   struct Avatar *characterList;
 };


 struct Avatar {
   char* name;
   struct Room *room;
   struct Item *itemList;
   struct Avatar *next;
 };


struct Room *room(char* name, struct Room *North, struct Room *South, struct Room *East, struct Room *West, struct Item *itemList, struct Avatar *characterList);

struct Avatar *avatar(char* name, struct Room *room, struct Item *itemList, struct Avatar *next);

void buildBoard(struct Room *board[]);

void shuffleRooms(struct Room *board[]);

char* getAvatarName(struct Avatar *avatar);

struct Item *AvatarInventory(struct Avatar *avatar);

struct Room *AvatarLoc(struct Avatar *avatar);

void shuffleAvatars(struct Avatar *avatarArr[], struct Room *board[]);
void printNorth(struct Room *room);
void printSouth(struct Room *room);
void printEast(struct Room *room);
void printWest(struct Room *room);
void printCharacters(struct Room *room);  


    
