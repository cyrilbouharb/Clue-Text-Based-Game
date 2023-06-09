#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rooms.h"
#include "items.h"

//goal: randomize the items and put them inside the rooms
// not all rooms are going to have items because we have 6 items
// and 9 rooms.
// param struct Item *items[]: pointer to the items array containing all items
//param struct Room *board[]: pointer to the board array
// return: type void. Not returning anything.
  void shuffleItems(struct Item *items[], struct Room *board[]) { 
    srand (time (NULL) );
    int i;
   for (i = 0; i < 6; i++) {
   int num = rand() % 9;
   board[num]->itemList = items[i];
   
   }
  }

  //goal: prints the list of commands available to get the player started and guide him
  // during the game
  // return: doesn't return anything. Type void.
  void help() {
	printf("List of Commands:\n");
	printf("--->list: Look up lists of items, rooms, and characters.\n");
	printf("--->look: See the room you're in, including the rooms in each direction, the characters in the room and the items in the room.\n");
	printf("--->go: Move avatar into the wanted direction (North, South, East, or West)\n");
	printf("--->take (type item name): Takes the item mentioned\n");
	printf("--->drop (type item name): Drops the item mentioned\n");
	printf("--->inventory: Checks the avatar's items in the inventory\n");
	printf("--->clue (type character name): Make a guess\n");
}
//goal: lists all the items present in the game, all the rooms, and all the
// characters
// param struct Item *itemList[]: pointer to the array of items 
// param struct Room *board[]: pointer to the array containing all 9 rooms
// param struct Avatar *avatarArray[]: pointer to the array of avatars
// return: type void. Not returning anything.
void list(struct Item *itemList[], struct Room *board[], struct Avatar *avatarArray[]) {
  int i, r, a;
  printf("\n THE LIST OF ITEMS:\n");
   for (i = 0; i < 6; i++) {
    printf("--->(%d): %s \n", i+1, itemList[i]->name);
  }
  printf("\n THE LIST OF ROOMS:\n");
	 for (r = 0; r < 9; r++) {
		printf("--->(%d): %s \n", r+1, board[r]->name);
	}
  printf("\n THE LIST OF CHARACTERS:\n");
   for (a = 0; a < 5; a++) {
    printf("--->(%d): %s \n", a+1, avatarArray[a]->name);
  }
}
//goal: generate a rumor that would give a hint without really
// exposing the muderer and making it obviouse
// param char* murderer: name of the murderer in this game (string).
// return: type void. Not returning anything. Only printing statements.
 void print_rumor(char* murderer) {
    if (strcmp("MissScarlett",murderer) == 0)  {

       printf("The rumor has it that the murderer has an S in their name.\n");

    } else if (strcmp("RevGreen",murderer) == 0) {

      printf("The rumor has it that the murderer has an E in their name.\n");

    } else if (strcmp("ColonelMustard",murderer) == 0) {

      printf("The rumor has it that the murderer has an E in their name.\n");

    } else if (strcmp("ProfessorPlum",murderer) == 0) {

      printf("The rumor has it that the murderer has an S in their name.\n");

    } else if (strcmp("Mrs.Peacock",murderer) == 0) {

      printf("The rumor has it that the murderer has an S in their name.\n");
    } 
 }

 int main() {  
  printf("\e[1;1H\e[2J");
 printf(".----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n");
printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
printf("| |     ______   | || |   _____      | || | _____  _____ | || |  _________   | || |  ________    | || |     ____     | |\n");
printf("| |   .' ___  |  | || |  |_   _|     | || ||_   _||_   _|| || | |_   ___  |  | || | |_   ___ `.  | || |   .'    `.   | |\n");
printf("| |  / .'     |  | || |    | |       | || |  | |    | |  | || |   | |_  |  | || |   | |   `.  | || |  /  .--.     | |\n");
printf("| |  | |         | || |    | |   _   | || |  | '    ' |  | || |   |  _|  _   | || |   | |    | | | || |  | |    | |  | |\n");
printf("| |   `.___.'  | || |   _| |__/ |  | || |    `--' /   | || |  _| |___/ |  | || |  _| |___.' / | || |    `--'  /  | |\n");
printf("| |   `._____.'  | || |  |________|  | || |    `.__.'    | || | |_________|  | || | |________.'  | || |   `.____.'   | |\n");
printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
printf("'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
  printf("\n");
  printf("\n");
  printf("\n");  
  printf("\n"); 
  printf("\n");  
  printf("\n");
  printf("\n");  
  printf("\n"); 
  printf("CLUE: A CLASSIC DETECTIVE GAME\n");
  printf("The object of the game is to determine who murdered the game's victim, where the crime took place, and which weapon was used.\n");
  printf("There are five suspects. You need to solve this murder mystery before you run out of attempts.\n");
  printf("Good Luck!\n");   
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("type ---> help to see the list of commands!\n");
  printf("---> ctrl C to exit the game\n");   

   //creating the 6 items
   struct Item *Candlestick = item("Candlestick",NULL);
   struct Item *Dagger = item("Dagger",NULL);
   struct Item *LeadPipe = item("LeadPipe",NULL);
   struct Item *Revolver = item("Revolver", NULL);
   struct Item *Rope = item("Rope", NULL);
   struct Item *Wrench = item("Wrench", NULL);
  
   //creating the 9 rooms
   struct Room *Kitchen = room("Kitchen", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Ballroom = room("Ballroom",NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Conservatory = room("Conservatory", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *DiningRoom = room("DiningRoom", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Cellar = room("Cellar", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Library = room("Library", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Lounge = room("Lounge", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Hall = room("Hall", NULL, NULL, NULL, NULL, NULL, NULL);
   struct Room *Study = room("Study", NULL, NULL, NULL, NULL, NULL, NULL);
 
  //creating the 5 avatars
  struct Avatar *avatar1 = avatar("MissScarlett", NULL, NULL, NULL);
  struct Avatar *avatar2 = avatar("RevGreen", NULL, NULL, NULL);
  struct Avatar *avatar3 = avatar("ColonelMustard", NULL, NULL, NULL);
  struct Avatar *avatar4 = avatar("ProfessorPlum", NULL, NULL, NULL);
  struct Avatar *avatar5 = avatar("Mrs.Peacock", NULL, NULL, NULL);

 //putting each struct type in arrays 
  struct Item *itemList[6] = {Candlestick, Dagger, LeadPipe, Revolver, Rope, Wrench};
  struct Room *board[9] = {Kitchen, Ballroom, Conservatory, DiningRoom, Cellar, Library, Lounge, Hall, Study};
  struct Avatar *avatarArray[5] = {avatar1, avatar2, avatar3, avatar4, avatar5};

//shuffling 
 shuffleRooms(board);
 buildBoard(board);
 shuffleAvatars(avatarArray, board);
 shuffleItems(itemList, board);

//choosing the answers "clues" to the game randomly
//and puting these answers in an array
 srand( time(NULL) );
 
  int avatarIndex = rand() % 5;
  int roomIndex = rand() % 9;
  int itemIndex = rand() % 6;
  char* answers[3] = {avatarArray[avatarIndex]->name, board[roomIndex]->name, itemList[itemIndex]->name};

 struct Avatar *player = avatar("Player", board[0], NULL, NULL);

int attempts = 0;

while (attempts < 10) {
  char input[100];
  scanf("%s", input);
  //case user types help: calling the help method to see the list of commands
  if (strcmp(input, "help") == 0) {
			help();
	}
  //case user types list: calling the list method to print out the lists of 
  // items, characters and rooms
		else if (strcmp(input, "list") == 0) {
			list(itemList, board,avatarArray);
		}
    //calls several functions that let's the user know their surroundigs
    // prints the room they're at and the rooms in each of the 4 diretions
    // of that room (North,South, West, East)
    // it also calls the method that prints the characters present in that room
    // and calls the method that prints the list of items present in that room
		else if (strcmp(input, "look") == 0) {
      printf("You are in the room: %s\n",player->room->name);
      printNorth(player->room);
      printSouth(player->room);
      printEast(player->room);
      printWest(player->room);
      printf("\n");
      printItems(player->room->itemList);
      printCharacters(player->room);
		}
    //changes the player's room status based on the direction they type
    // checks for edge cases where the direction they typed isn't valid
    else if (strcmp(input, "go") == 0) {
      printf("Type the direction you want to go to down below: (North, South, East, West)\n");
      bool boolean = false;
      while (boolean != true){
      char niput[100];
      scanf("%s", niput);
      if(strcmp(niput, "North") == 0){
        if( player->room->North != NULL) {
          printf("You went to the room to your North!\n");
          player->room = player->room->North;
          printf("You are now in the room %s\n", player->room->name);
          boolean = true;
        } else {
          printf("YOU CAN'T GO IN THIS DIRECTION! TRY ANOTHER ONE\n");
        }
        printf("***********************************************************************************\n");
      }
      else if(strcmp(niput, "South") == 0){
        if( player->room->South != NULL) {
          printf("You went to the room to your South!\n");
          player->room = player->room->South;
          printf("You are now in the room %s\n", player->room->name);
          boolean = true;
        } else {
           printf("YOU CAN'T GO IN THIS DIRECTION! TRY ANOTHER ONE\n");
        }
        printf("***********************************************************************************\n");
      }
      else if(strcmp(niput, "East") == 0){
        if( player->room->East != NULL) {
          printf("You went to the room to your East!\n");
          player->room = player->room->East;
          printf("You are now in the room %s\n", player->room->name);
          boolean = true;
        } else {
           printf("YOU CAN'T GO IN THIS DIRECTION! TRY ANOTHER ONE\n");
        }
        printf("***********************************************************************************\n");
      }
      else if(strcmp(niput, "West") == 0){
        if( player->room->West != NULL) {
          printf("You went to the room to your West!\n");
          player->room = player->room->West;
          printf("You are now in the room %s\n", player->room->name);
          boolean = true;
        } else {
           printf("YOU CAN'T GO IN THIS DIRECTION! TRY ANOTHER ONE\n");
        }
        printf("***********************************************************************************\n");
      }
      else {
        printf("Type again!\n");
      }
        
      }
      //Let's the player add an item to their inventory while dropping it from the 
      // room's itemList. Checks for edge cases if either the item name isn't valid
      // or the item isn't in the room they're currently in.
    } else if (strcmp(input, "take") == 0) {
      printf("Type the item you would like to take:\n ");
      bool boolean = false;
      while (boolean != true){
        char sinput[100];
        scanf("%s", sinput);
          if (has_item(player->room->itemList, sinput)) {
            struct Item *item = drop_item(player->room->itemList, sinput);
             player->itemList = add_item(player->itemList, item);
             boolean = true;
          }else {
            printf("There is no such item. Try another.\n");
     }
      printf("***********************************************************************************\n");
      }
       //Let's the player drop an item from their inventory. adding the item to the 
      // room's itemList. Checks for edge cases if either the item name isn't valid
      // or the item isn't in the avatar's inventory .
    } else if (strcmp(input, "drop") == 0){
        printf("Type the item you would like to drop:\n ");
        printItems(player->itemList);
        bool boolean = false;
        while (boolean != true){
          char sinput[100];
          scanf("%s", sinput);
          struct Item *item = drop_item(player->itemList, sinput);
          if (item == NULL){
             printf("NO SUCH ITEM. TRY ANOTHER.\n");
          } 
          else {
            add_item(player->room->itemList, item);
            printf("The item has been dropped!\n");
            boolean = true;
          }
          printf("***********************************************************************************\n");
        }
      //calls the prinItems function to print all the items present in
      //the avatar's inventory.
    } else if (strcmp(input, "inventory") == 0) {
      printf("The items in the avatar's inventory are: \n");
      printItems(player->itemList);
      printf("***********************************************************************************\n");

    } 
    // allow the user to type a CHARACTER name while giving them a hint. Move the character stated 
    // in the command to the same room of avatar. 
    // If the character name doesn't match the answer allows it to retype an item's name.
    // If they hit all 3 matches related to the Character, Item, Room before 9 attempts
    // they win else they loose.
    else if (strcmp(input, "clue") == 0){
      int correct_guesses = 0;
       printf("Type a character's name: \n");
       printf("Choose who you think did it: MissScarlett, RevGreen, ColonelMustard, ProfessorPlum, Mrs.Peacock\n");
       print_rumor(answers[0]);
       char sinput[100];
       scanf("%s", sinput);
       attempts++;
       int findAvatar = 0;

       while (findAvatar < 5 && strcmp(avatarArray[findAvatar]->name,sinput) != 0){
         findAvatar++;
       }
       avatarArray[findAvatar]->room = player->room;

       if (strcmp(answers[0], avatarArray[findAvatar]->name) == 0){
         printf("Character Match\n");
         correct_guesses++;
         if ( strcmp(answers[1], player->room->name) == 0) {
         printf("Room Match\n");
         correct_guesses++;
         }
         else{
           printf("Room Doesn't Match\n");
         }
         if (has_item(AvatarInventory(player), answers[3]) || has_item(player->room->itemList, answers[3])) {
         printf("Item Match \n");
         correct_guesses++;
         }
         else {
           printf("Item Don't Match \n");
         }
       } else {
         attempts++;
         printf("WRONG CHARACTER. TYPE IN AN ITEM'S NAME:\n");
         printf("The items present in the game are: Candlestick, Dagger, LeadPipe, Revolver, Rope, Wrench. \n");
         char ninput[100];
         scanf("%s", ninput);
         if (strcmp(answers[3], ninput) == 0) {
         printf("Item Match \n");
         } else{
         printf("Item doesn't match try again. Type from the command table\n");
        }
       }
       if (correct_guesses == 3) {
				printf("You have solved the mystery!\n");
				attempts = 0;
				break;
			}
    }
		else {
			printf("Unkown command, try again\n");
			continue;
		}
  }
  
  if (attempts == 10) {
    printf("GAME OVER. YOU LOST\n");
  }

  int i, j, k;

  for (i = 0; i < 9; i++){
		free(board[i]);
	}
  for (j = 0; i < 6; j++){
		free(itemList[i]);
	}
  for (k = 0; k < 5; k++) {
    free(avatarArray[k]);
  }
  free(player);

 return 0;
}
 

  
