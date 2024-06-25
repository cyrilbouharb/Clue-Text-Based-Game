# Clue: A Text Adventure Game

## Overview
**Clue** is a text adventure game written in C, where players use text commands to control characters, influence the environment, and navigate through a virtual world to solve a murder mystery. The objective is to determine who the murderer is, where the crime was committed, and which weapon was used.

## Compilation Instructions
To compile the code, follow these steps:

1. **Compile each source file into an object file:**
   ```bash
   gcc -c adventure.c -o adventure.o
   gcc -c rooms.c -o rooms.o
   gcc -c items.c -o items.o
   ```

2. **Link all object files into a single executable:**
   ```bash
   gcc adventure.o rooms.o items.o -o prog
   # With debugging and address sanitizer
   gcc adventure.o rooms.o items.o -o prog -g -fsanitize=address
   ```

3. **Run the program:**
   ```bash
   ./prog
   ```

## Project Structure
- **`adventure.c`**: Main game logic and command table implementation.
- **`rooms.c`**: Contains the `buildBoard` method which builds the game board, connects rooms via pointers, and includes the `Room` struct definition.
- **`items.c`**: Defines the `Item` struct and manages item interactions.

### Memory Management
- Dynamic memory allocation is used extensively throughout the project for creating rooms, avatars, and items using `malloc`.
- At the end of the game or upon exiting, all dynamically allocated memory is properly freed using `free`.

### Game Mechanics
- **Room Initialization**: Rooms are initialized and shuffled in `adventure.c` using `shuffleRooms()` to randomize their locations.
- **Item Placement**: Items are distributed across rooms using `shuffleItems()`, ensuring that each room has at most one item at the start.
- **Mystery Setup**: Random selection of one room, one item, and one character to set up the mystery scenario (see lines 154-161 in `adventure.c`).

## Features
- **Linked Lists**: Used for managing items within rooms and avatars.
- **Robust Command System**: Allows for complex player interactions within the game world.

## Style and Aesthetics
The code is developed in Visual Studio Code, optimized for readability and maintainability. Please note that viewing or editing the code in different editors (like Vim) might alter the appearance of indentation and formatting.

## Final Notes
For further details on the implementation and specific functions, please refer to the comments within the code files. Enjoy exploring and solving the mystery in **Clue**!



https://github.com/cyrilbouharb/Clue-Text-Based-Game/assets/55791197/6055cd26-d83b-4005-895e-eb1fbdeb0814





