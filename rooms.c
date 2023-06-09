#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rooms.h"
#include "items.h"
#include <time.h>        

// goal: creates a Room struct with the name of the room and pointers to each of the 4 direction
//and a pointer to the itemList in that room, and the characterList in it too
// param name: represents the name of the room
//
// return: a Room struct
 struct Room *room(char* name, struct Room *North, struct Room *South, struct Room *East, struct Room *West, struct Item *itemList, struct Avatar
    *characterList) {
     
     struct Room *newRoom = (struct Room *) malloc(sizeof(struct Room));
     if (newRoom == NULL) {
          return NULL;
     }

     newRoom->name = name;
     newRoom->North = North;
     newRoom->South = South;
     newRoom->East = East;
     newRoom->West = West;
     newRoom->itemList = itemList;
     newRoom->characterList = characterList;
     
     return newRoom;
}
 //goal: prints the room to our North 
// param struct Room *room: pointer to the room
// return: type void. Not returning anything.
//
 void printNorth(struct Room *room){
     if (room->North == NULL){
        printf("No Room to your North \n");
     }
     else{
        printf("The room to your North is: %s\n", room->North->name);
     }
 }

//goal: prints the room to our South 
// param struct Room *room: pointer to the room
// return: type void. Not returning anything.
//
  void printSouth(struct Room *room){
     if (room->South == NULL){
        printf("No Room to your South\n");
     }
     else {
        printf("The room to your South is: %s\n", room->South->name);
     }
 }

//goal: prints the room to our East
// param struct Room *room: pointer to the room
// return: type void. Not returning anything.
//
  void printEast(struct Room *room){
     if (room->East == NULL){
        printf("No Room to your East\n");
     }
     else {
        printf("The room to your East is: %s\n", room->East->name);
     }
 }

//goal: prints the room to our West 
// param struct Room *room: pointer to the room
// return: type void. Not returning anything.
//
  void printWest(struct Room *room){
     if (room->West == NULL){
        printf("No Room to your West\n");
     }
     else {
        printf("The room to your West is: %s\n", room->West->name);
     }
 }

 //goal: builds the board 3x3 so it fits the description given to us in  [ROOM0] [ROOM1] [ROOM2]
// the instructions. We are using an array here of size 9.               [ROOM3] [ROOM4] [ROOM5]
 // param struct Room *board[]: pointer to the board array               [ROOM6] [ROOM7] [ROOM8]
 // return: type void. Not returning anything.
 //
 void buildBoard(struct Room *board[]) {                          
     int roomNum;                                                   
     for( roomNum = 0; roomNum < 9; roomNum++) {                     
        switch (roomNum) {
           case 0:
            board[0]->West = board[1];
            board[0]->South = board[3];
            board[0]->East = NULL;
            board[0]->North = NULL; 
                    break;
           case 1:
            board[1]->East = board[0];
            board[1]->West = board[2];
            board[1]->South = board[4];
            board[1]->North = NULL;
	            break;   
           case 2:
            board[2]->East = board[1];
            board[2]->South = board[5];
            board[2]->West = NULL;
            board[2]->North = NULL;
                    break;
           case 3:
            board[3]->North = board[0];
            board[3]->South = board[6];
            board[3]->West = board[4];
            board[3]->East = NULL;
                    break;
           case 4:
            board[4]->North = board[1];
            board[4]->South = board[7];
            board[4]->West = board[5];
            board[4]->East = board[3];
                    break;
           case 5:
            board[5]->North = board[2];
            board[5]->South = board[8];
            board[5]->West = NULL;
            board[5]->East = board[4];
                    break;
           case 6:
            board[6]->North = board[3];
            board[6]->South = NULL;
            board[6]->West = board[7];
            board[6]->East = NULL;  
                    break;
           case 7:
            board[7]->North = board[4];
            board[7]->South = NULL;
            board[7]->West = board[8];
            board[7]->East = board[6]; 
                    break;
           case 8:
            board[8]->North = board[5];
            board[4]->South = NULL;
            board[4]->West = NULL;
            board[4]->East = board[7]; 
                    break;
    }
   }
  }
//WATCHED A YOUTUBE VIDEO BY PORTFOLIO COURSES TITLED SHUFFLING AN ARRAY | C PROGRAMMING EXAMPLE
//goal: randomize the rooms positions so each game they're different
// param struct Room *roomList[]: pointer to the roomList array
// return: type void. Not returning anything.
//
 void shuffleRooms( struct Room *roomsList[]) {
     srand( time(NULL) );  //seeding the rand function with a different number each time the program
                           // runs to ensure that the random numbers are different

     int i;
     for ( i = 0; i < 9; i++) {

      int swapIndex = rand() % 9;
      struct Room *temp = roomsList[i];
      roomsList[i] = roomsList[swapIndex];
      roomsList[swapIndex] = temp;

    }
 }
// goal: creates an Avatar struct with the name of the avatar
//and a pointer to the itemList's in their inventory, and a next pointer.
// param char* name: represents the name of the avatar
// param struct Room *room: represents the room they're in
// param struct Item *itemList: represents the items in the avatar' inventory
// param struct Avatar *next: pointer to the next Avatar.
// return: an Avatar struct.
 struct Avatar *avatar(char* name, struct Room *room, struct Item *itemList, struct Avatar *next) {
      struct Avatar *newAvatar = (struct  Avatar *) malloc(sizeof(struct Avatar));
      if ( newAvatar == NULL) {
          return NULL;
      }

      newAvatar->name = name;
      newAvatar->room = room;
      newAvatar->itemList = itemList;
      newAvatar->next = NULL;
     
      return newAvatar;
 }



// goal: gets the name from an Avatar struct
// param struct Avatar *avatar: pointer that point to a struct representing an Avatar
// return: a char pointer to the string representing the name of the avatar
//
 char* getAvatarName(struct Avatar *avatar) {
      return avatar->name;
}

 // goal: gets the avatr's inventory
// param struct Avatar *avatar: pointer that point to a struct representing an Avatar
// return: a pointer to the avatar's itemList.
//
 struct Item *AvatarInventory(struct Avatar *avatar) {
      return avatar->itemList;
}

// goal: gets the avatar's location
// param struct Avatar *avatar: pointer that point to a struct representing an Avatar
// return: a pointer to the room the avatar's in
//
 struct Room *AvatarLoc(struct Avatar *avatar) {
      return avatar->room;
} 

// goal: prints all the characters in the room
// param struct Room *room: pointer to the room we want to use
// return: type void. We aren't returning anything. Only printing.
//
void printCharacters(struct Room *room){
   printf("These are the characters in this current room: ");
   struct Avatar *curr = room->characterList; 
   if(curr == NULL) printf("There is none!\n \n");
   while(curr != NULL){
      printf("%s\n", getAvatarName(room->characterList));
      curr = curr->next;
   }
  
}

//goal: randomize the avatars positions and assign them to rooms
//also assign the avatars to the rooms's character list
// param struct Avatar *avatarArr[]: pointer to the avatar array containing all characters
//param struct Room *board[]: pointer to the board array
// return: type void. Not returning anything.
//
void shuffleAvatars(struct Avatar *avatarArr[], struct Room *board[]) {
   srand( time(NULL) );
   for (int i = 0; i < 5; i++) {
      int num = rand() % 9;
      avatarArr[i]->room = board[num];
      if (board[num]->characterList == NULL) {
          board[num]->characterList = avatarArr[i];
       }
       else{
      board[num]->characterList->next = avatarArr[i];
       }
   }
}



