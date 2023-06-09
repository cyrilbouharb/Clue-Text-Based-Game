 This is a text adventure game written in C. Players use text commands to control characters, influence the environment, and navigate a virtual world.
 This game called "Clue" is a murder mystery game whose objective is to determine who murdered the game's victim, where the crime took place and which weapon
 was used.




-->How to compile the code:
  -gcc each file individually : gcc -c adventure.c -o adventure.o
                                gcc -c rooms.c -o rooms.o
                                gcc -c items.c -o items.o
 -link all the objects file:    gcc adventure.o rooms.o items.o -o prog and gcc adventure.o rooms.o items.o -o prog -g -fsanitize=address


 -Run the code: ./prog
 
--------------------------------
The board was built in the rooms.c file using the buildBoard() method. Rooms are connected via pointers. We created the Room struct in rooms.c and
the Avatar struct too, the instances of room and avatar were alllocated dynamically using malloc. We created an
Item struct in items.c also using malloc. We used pointers all along the project in our functions in all 3
files. At the end in adventure.c we dellocate memory using free. (For more details check the cooments in the files). We randomly initialize the location of each
room by calling in adevnture.c the function created in rooms.c called shuffleRooms(). We create the 9 rooms, 6 items, 5 characters in adventure.c. We place the items randomly in each room using the
shuffleItems() function in adventure.c in a way that each room contains at most 1 item at the beggining. Line 154-161 (Vscode) in adventure.c we're randomly picking a room, item and a character as the
answer. The rooms and the avatars have a linked list of items check the file rooms.c. The table of commands is implemented in adventure.c. All commands are implemented and work.
For the style and aesthetic I wrote in vscode so the code might look different in vim or other in terms of indentation. 






I hope, I answered all the required questions and described clearly the overall structure of my code. 
Enjoy the game!





 
