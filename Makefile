##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = src/core/game_loop.c \
	src/core/loop.c \
	src/core/main.c \
	src/ducks/bird_list.c \
	src/ducks/click.c \
	src/ducks/create_bird.c \
	src/ducks/destroy_bird.c \
	src/ducks/update_birds.c \
	src/events/analyse_event.c \
	src/gameplay/difficulty.c \
	src/gameplay/waves.c \
	src/HUD/cursor.c \
	src/HUD/hud.c \
	src/HUD/life.c \
	src/menu/main_menu.c \
    src/sprite/background.c \
	src/window/create_window.c \
	src/window/framerate.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -I./lib/my/my_printf
FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME = my_hunter
LIB_PRINTF = -Llib/my/my_printf -lmy


all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C lib/my
		clang $(OBJ) -o $(NAME) $(FLAGS) $(LIB_PRINTF) 
		rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/my/my_printf clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my/my_printf fclean

re: fclean all