/*
** EPITECH PROJECT, 2025
** menu.h
** File description:
** menu header
*/

#ifndef _MENU_H_
    #define _MENU_H_

    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include "../lib/my/my_printf/my_printf.h"
    #include "../lib/my/my.h"

typedef struct menu_s {
    sfSprite *background;
    sfTexture *texture;
    sfSprite *button_play;
    sfSprite *button_shop;
    sfSprite *button_settings;
    sfSprite *button_exit;
    sfIntRect rect_panel;
    sfIntRect rect_button;
    sfFont *font;
    sfText *text_play;
    sfText *text_shop;
    sfText *text_settings;
    sfText *text_exit;
    sfSoundBuffer *click_buffer;
    sfSound *click_sound;
} menu_t;

void center_text(sfText *text, sfSprite *sprite);
int update_menu(menu_t *menu, sfRenderWindow *window);
int sprite_clicked(sfSprite *sprite, sfRenderWindow *w, sfEvent *ev);
menu_t *create_menu(void);
void menu_draw(menu_t *menu, sfRenderWindow *window);

#endif /* _MENU_H_ */
