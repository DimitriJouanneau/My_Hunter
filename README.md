**MY_HUNTER** – Duck Hunt Inspired Game
*Description :*

*MY_HUNTER* is an Epitech project consisting of developing a 2D video game, written in C, using the CSFML library.

The game is inspired by the classic Duck Hunt gameplay. The player takes the role of a hunter whose goal is to shoot ducks appearing on the screen and moving from one side to the other.
This project focuses on handling user inputs, animated sprites, and time-based movements using CSFML clocks.

*Project objectives :*

    · Develop a basic 2D video game
    · Handle mouse input events
    · Display animated sprites using sprite sheets
    · Manage moving elements (translation)

*Games rules :*

    · The player is the hunter
    · Ducks appear on the screen at each waves
    · Ducks move continuously across the window
    · The player can click on ducks to shoot them


**Compilation**

The project is compiled via a Makefile containing the following rules:
```bash
make
make re
make clean
make fclean
```

**Usage**
Start the game
```bash
./my_hunter
```

Show help
```bash
./my_hunter -h
```

*Display :*

    · Window size between 800x600 and 1920x1080
    · Animated sprites
    · Time-based animations using sfClock
    · Limited frame rate

**Project structure :**
```
my_hunter/
├── assets/
├── include/
├── src/
│   ├── audio/
│   ├── core/
│   ├── ducks/
│   ├── events/
│   ├── gameplay/
│   ├── HUD/
│   ├── menu/
│   ├── sprite/
│   ├── display/
│   └── window/
├── Makefile
└── README.md
```
<img width="1068" height="614" alt="hunter_rd_menu" src="https://github.com/user-attachments/assets/5b2cdf66-14af-44e6-9926-20bcb4bdd74c" />
<img width="1076" height="624" alt="hunter_rd_game" src="https://github.com/user-attachments/assets/707bfd43-7ad3-4345-9e61-73d7c21563d8" />


Jouanneau Dimitri                                                                                                                                                                                                   
Student at Epitech
                          
