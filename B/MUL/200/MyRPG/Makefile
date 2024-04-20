##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

LIB =		./lib/my_abs.c \
			./lib/my_free.c \
			./lib/my_getfloat.c \
			./lib/my_getnbr.c \
			./lib/my_getsize_array.c \
			./lib/my_isnbr.c \
			./lib/my_issep.c \
			./lib/my_itoa.c \
			./lib/my_lenword.c \
			./lib/my_nbline.c \
			./lib/my_nbrlen.c \
			./lib/my_nbword.c \
			./lib/my_pow.c \
			./lib/my_putarray.c \
			./lib/my_putchar.c \
			./lib/my_putlong.c \
			./lib/my_putnbr.c \
			./lib/my_putstr.c \
			./lib/my_skipsep.c \
			./lib/my_str_to_word_array.c \
			./lib/my_strcat.c \
			./lib/my_strcmp.c \
			./lib/my_strcpy.c \
			./lib/my_strdup.c \
			./lib/my_strlen.c \
			./lib/my_strtok.c \
			./lib/my_swap.c \
			./lib/my_tokarray.c \
			./lib/my_word_array_to_str.c \

SRC	=		./src/main.c \
			./src/update.c \
			./src/create.c \
			./src/malloc.c \

MENU = 		./src/menu/create.c \
			./src/menu/update.c \

MOUSE =		./src/mouse/hover.c \
			./src/mouse/click.c \
			./src/mouse/compute.c \
			./src/mouse/activate.c \

STORY = 	./src/story/create.c \
			./src/story/update.c \

WINDOW =	./src/window/create.c \
			./src/window/manage.c \

ANIMATION = ./src/anim/create.c \
			./src/anim/update.c \
			./src/anim/player/update_player.c \
			./src/anim/player/update_collision.c \
			./src/anim/player/update_attack.c \
			./src/anim/player/walk.c \
			./src/anim/player/create.c \
			./src/anim/bandit/walk.c \
			./src/anim/bandit/create.c \
			./src/anim/bandit/update.c \
			./src/anim/bandit/short_zone_view.c \
			./src/anim/bandit/long_zone_view.c \
			./src/anim/bandit/all_moves_bandit.c \
			./src/anim/npc/update.c \
			./src/anim/npc/create.c \
			./src/anim/npc/create2.c \
			./src/anim/npc/create3.c \
			./src/anim/boss/create.c \
			./src/anim/boss/update.c \
			./src/anim/npc/update2.c \
			./src/anim/npc/update3.c \
			./src/anim/npc/update4.c \
			./src/anim/boss/walk.c \
			./src/anim/boss/short_zone_boss.c \
			./src/anim/boss/long_zone_boss.c \
			./src/anim/boss/all_moves_boss.c \

OBSTACLES = ./src/obstacles/open_file.c \
			./src/obstacles/create_objects.c \
			./src/obstacles/create.c \
			./src/obstacles/update.c \
			./src/obstacles/check_object.c \
			./src/obstacles/create_collisions.c \

VIEW =		./src/view_player/create.c \
			./src/view_player/update.c \

HEALTH =	./src/health/create.c \
			./src/health/update.c \

SETTINGS =	./src/settings/create.c \
			./src/settings/create_text.c \
			./src/settings/update.c \

MENU_GAME =	./src/menu_game/update.c \
			./src/menu_game/create.c \

MUSIC =		./src/music/create.c \
			./src/music/update.c \

CHARACTERISTICS =	./src/characteristics/create.c \
					./src/characteristics/update.c \
					./src/characteristics/update2.c \

LVL =				./src/characteristics/level/update.c \
					./src/characteristics/level/upgrade_level.c\

INVENTORY =			./src/inventory/create.c \
					./src/inventory/update.c \
					./src/inventory/add_item.c \

DESTROY =	./src/destroy/destroy.c \
			./src/destroy/destroy2.c \

OBJ	=		$(LIB:.c=.o) \
			$(SRC:.c=.o) \
			$(MENU:.c=.o) \
			$(MOUSE:.c=.o) \
			$(STORY:.c=.o) \
			$(WINDOW:.c=.o) \
			$(ANIMATION:.c=.o) \
			$(OBSTACLES:.c=.o) \
			$(VIEW:.c=.o) \
			$(HEALTH:.c=.o) \
			$(SETTINGS:.c=.o) \
			$(MENU_GAME:.c=.o) \
			$(MUSIC:.c=.o) \
			$(CHARACTERISTICS:.c=.o) \
			$(LVL:.c=.o) \
			$(INVENTORY:.c=.o) \
			$(DESTROY:.c=.o) \

NAME	=	my_rpg

LIB_CSFML = -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

CFLAGS	=	-Wall -Wextra -I include/

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(LIB_CSFML) -lm

all: 		$(NAME)

clean:
			rm -f $(OBJ)
			find . \( -name "#*#" -o -name "*~" \) -delete

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

z:			fclean
			clear

debug:		CFLAGS += -g3
debug:		re
