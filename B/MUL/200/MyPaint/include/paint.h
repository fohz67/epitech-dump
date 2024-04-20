/*
** EPITECH PROJECT, 2022
** paint.h
** File description:
** paint.h
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef PAINT_H
    #define PAINT_H

    #define LABEL "my_paint"
    #define HELP ""

    #define TOOLS 4
    #define TOOLBAR 3
    #define MOUSE_DECAL 11

    #define ABOUT_TITLE "About"
    #define ABOUT_CONTENT "bgayaud && nsamy"
    #define ABOUT_SIZE 200

    #define HELP_TITLE "Help"
    #define HELP_CONTENT "\
LES  OUTILS:\n\
    - La  gomme\n\
    - Le  pinceau\n\
    - La  palette  de  couleur\n\
    - Le  curseur,  pour  deplacer\n      \
la  feuille\n\n\
UTILISATION:\n\
    -> Modifier  la  taille  d'un\n        \
outil:  CLIC  DROIT  sur  un\n        \
outil.\n\
    -> Changer  la  couleur  du\n        \
pinceau:  CLIC GAUCHE\n        \
sur  la  palette  de\n        \
couleur.\n\n\
FICHIER:\n\
    Vous  pouvez  importer,\n\
    sauvegarder  ou  meme\n\
    ouvrir  un  fichier\n\
    directement  depuis  \"FILE\".\n\
    Vous  pouvez  egalement\n\
    selectionner  un  outils\n\
    depuis  le  menu  deroulant\n\
    \"EDIT\"."
    #define HELP_SIZE 900

    #define SIZE_FONT_TOOLBAR 45
    #define SIZE_FONT_ITEM 25

    #define SIZE_FONT_TITLE_MENU 50
    #define SIZE_FONT_CONTENT_MENU 23
    #define LETTER_SPACING 1

struct color_st {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
    sfTexture *color_picker;
    sfTexture *black_picker;
    int picker;
};

struct text_menu_st {
    sfRectangleShape *background;
    sfRectangleShape *box;
    sfRectangleShape *close;
    sfTexture *texture;
    sfText *title;
    sfText *content;
    sfBool isShowed;
};

struct frame_st {
    sfSprite *sheet;
    sfTexture *texture;
    sfUint8 *pixels;
    sfBool isMoved;
};

struct toolbar_item_st {
    sfText *text;
    sfBool isHover;
};

struct toolbar_st {
    sfRectangleShape *rect;
    sfText *text;
    sfBool isClicked;
    sfBool isHover;
    struct toolbar_item_st *item;
};

struct tool_dialog_black_st {
    sfRectangleShape *rect;
    sfRectangleShape *border;
    sfCircleShape *slider;
    sfRectangleShape *slider_bg;
    sfBool isHover;
};

struct tool_dialog_eraser_st {
    sfRectangleShape *rect;
    sfRectangleShape *border;
    sfCircleShape *shape_circle;
    sfRectangleShape *shape_rect;
    sfRectangleShape *button_circle;
    sfRectangleShape *button_rect;
    sfBool isHover;
    sfBool isHover_circle;
    sfBool isHover_rect;
};

struct tool_dialog_st {
    sfRectangleShape *rect;
    sfRectangleShape *border;
    sfCircleShape *slider;
    sfRectangleShape *slider_bg;
    sfBool isHover;
};

struct tool_st {
    sfRectangleShape *rect;
    sfRectangleShape *image;
    sfRectangleShape *shadow;
    sfTexture *texture;
    sfBool isLClicked;
    sfBool isRClicked;
    sfBool isHover;
    struct tool_dialog_st dg;
    struct tool_dialog_black_st dg_b;
    struct tool_dialog_eraser_st dg_e;
};

struct cursor_st {
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfTexture *texture;
    sfBool isOnSheet;
    int *all_radius;
    int tool_radius;
    int tool;
    int eraser_type;
    int dg;
};

struct gui {
    sfRectangleShape *white_sheet;
    sfRectangleShape *shadow;
    sfFont *font;
    struct tool_st *tool;
    struct toolbar_st *toolbar;
    struct cursor_st cursor;
    struct frame_st *frame;
    struct color_st color;
    struct text_menu_st text_menu;
};

// Library
float my_abs(float nb);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const  char *src);
int my_strlen(const char *str);


// Gui folder
    // Create subfolder
    void gui_create(struct gui *gui, sfRenderWindow *window);
    void tool_create(struct gui *gui);
    void toolbar_create(struct gui *gui);
    void tool_dialog_create(struct gui *gui);
    void dialog_create(struct gui *gui);
    void tool_dialog_eraser_create(struct gui *gui);

    // Update subfolder
    void gui_update(struct gui *gui, sfRenderWindow *window);
    void tool_dialog_update(struct gui *gui, sfRenderWindow *window);
    void tool_update(struct gui *gui, sfRenderWindow *window);
    void toolbar_update(struct gui *gui, sfRenderWindow *window);
    void toolbar_dialog_content_update(struct gui *gui, char *title,
    char *content);
    void toolbar_dialog_update(struct gui *gui, sfRenderWindow *window);
    void tool_show_eraser_states(struct gui *gui, int i);
    void tool_show_eraser(struct gui *gui, sfRenderWindow *window, int i);

// Mouse folder
    //Click subfolder
    void mouse_click(struct gui *gui, sfRenderWindow *window);
    void tool_click(struct gui *gui);
    void tool_dialog_slider(struct gui *gui, int i, sfRenderWindow *window);
    void toolbar_click(struct gui *gui, sfVector2i cursor);
    void tool_unclick(struct gui *gui, int i);
    void toolbar_dialog_click(struct gui *gui, sfVector2i cursor);
    void sheet_click(struct gui *gui, sfRenderWindow *window);

    //Hover subfolder
    void mouse_hover(struct gui *gui, sfRenderWindow *window);
    void tool_hover(struct gui *gui, sfVector2i cursor);
    void tool_dialog_hover(struct gui *gui, sfVector2i cursor);
    void toolbar_hover(struct gui *gui, sfVector2i cursor);

// Draw folder
    // Assets subfolder
    char *name_toolbar(int i);
    char *name_item(int i);
    int number_item(int i);
    char *texture_tool(int i);
    char *contain_tool_dialog(int i);
    char *contain_tool_type(int i);
    int resources_create(struct gui *gui);

    // Framebuf subfolder
    void framebuffer_create(struct gui *gui);
    void framebuffer_update(struct gui *gui, sfRenderWindow *window);

// ~ Folder
int malloc_components(struct gui *gui);
void create_components(struct gui *gui, sfRenderWindow *window);
void destroy(struct gui *gui, sfRenderWindow *window);
void manage_black(struct gui *gui, int selector);
void manage_window(struct gui *gui, sfRenderWindow *window, sfEvent event);
void manage_color(struct gui *gui, int selector);
int verif_env(char **env);

#endif
