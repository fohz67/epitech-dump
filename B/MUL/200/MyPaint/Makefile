##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LIB =			./lib/my_abs.c \
				./lib/my_strlen.c \
				./lib/my_strcmp.c \
				./lib/my_strcpy.c \
				./lib/my_strdup.c

SRC =			./src/main.c \
				./src/manage.c \
				./src/destroy.c \
				./src/components.c

GUI_CREATE =	./src/gui/create/gui_create.c \
				./src/gui/create/tool_create.c \
				./src/gui/create/tool_dialog_create.c \
				./src/gui/create/toolbar_create.c \
				./src/gui/create/toolbar_dialog_create.c \
				./src/gui/create/tool_dialog_eraser_create.c

GUI_UPDATE =	./src/gui/update/gui_update.c \
				./src/gui/update/tool_update.c \
				./src/gui/update/tool_dialog_update.c \
				./src/gui/update/toolbar_update.c \
				./src/gui/update/toolbar_dialog_update.c \
				./src/gui/update/tool_dialog_eraser_update.c

MOUSE_CLICK =	./src/mouse/click/click.c \
				./src/mouse/click/tool_click.c \
				./src/mouse/click/toolbar_click.c \
				./src/mouse/click/toolbar_dialog_click.c \
				./src/mouse/click/sheet_click.c \
				./src/mouse/click/tool_dialog_click.c

MOUSE_HOVER =	./src/mouse/hover/hover.c \
				./src/mouse/hover/tool_hover.c \
				./src/mouse/hover/toolbar_hover.c

DRAW_ASSETS =	./src/draw/assets/assets.c \
				./src/draw/assets/assets2.c \
				./src/draw/assets/resources.c

DRAW_FRAMEBUF = ./src/draw/framebuf/framebuffer_create.c \
				./src/draw/framebuf/framebuffer_update.c

OBJ =			$(LIB:.c=.o) \
				$(SRC:.c=.o) \
				$(GUI_CREATE:.c=.o) \
				$(GUI_UPDATE:.c=.o) \
				$(MOUSE_CLICK:.c=.o) \
				$(MOUSE_HOVER:.c=.o) \
				$(DRAW_ASSETS:.c=.o) \
				$(DRAW_FRAMEBUF:.c=.o)

NAME = 			my_paint

CFLAGS = 		-I ./include -W -Wall -Wextra

FL = 			-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

$(NAME):		$(OBJ)
				gcc $(OBJ) -o $(NAME) $(FL)

all:			$(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

z:				fclean
				clear
