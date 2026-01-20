/*
** EPITECH PROJECT, 2025
** main_menu.c
** File description:
** main menu
*/

#include "../../include/menu.h"

static void init_menu_text(menu_t *menu)
{
    menu->text_play = sfText_create();
    menu->text_shop = sfText_create();
    menu->text_settings = sfText_create();
    menu->text_exit = sfText_create();
    sfText_setFont(menu->text_play, menu->font);
    sfText_setFont(menu->text_shop, menu->font);
    sfText_setFont(menu->text_settings, menu->font);
    sfText_setFont(menu->text_exit, menu->font);
    sfText_setString(menu->text_play, "PLAY");
    sfText_setString(menu->text_shop, "SHOP");
    sfText_setString(menu->text_settings, "SETTINGS");
    sfText_setString(menu->text_exit, "EXIT");
    sfText_setCharacterSize(menu->text_play, 40);
    sfText_setCharacterSize(menu->text_shop, 40);
    sfText_setCharacterSize(menu->text_settings, 40);
    sfText_setCharacterSize(menu->text_exit, 40);
    sfText_setFillColor(menu->text_play, sfWhite);
    sfText_setFillColor(menu->text_shop, sfWhite);
    sfText_setFillColor(menu->text_settings, sfWhite);
    sfText_setFillColor(menu->text_exit, sfWhite);
}

static void init_menu_buttons(menu_t *menu)
{
    menu->button_play = sfSprite_create();
    menu->button_shop = sfSprite_create();
    menu->button_settings = sfSprite_create();
    menu->button_exit = sfSprite_create();
    sfSprite_setTexture(menu->button_play, menu->texture, sfTrue);
    sfSprite_setTexture(menu->button_shop, menu->texture, sfTrue);
    sfSprite_setTexture(menu->button_settings, menu->texture, sfTrue);
    sfSprite_setTexture(menu->button_exit, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->button_play, menu->rect_button);
    sfSprite_setTextureRect(menu->button_shop, menu->rect_button);
    sfSprite_setTextureRect(menu->button_settings, menu->rect_button);
    sfSprite_setTextureRect(menu->button_exit, menu->rect_button);
}

static void set_buttons_position(menu_t *menu)
{
    sfSprite_setPosition(menu->button_play, (sfVector2f){430, 100});
    sfSprite_setPosition(menu->button_shop, (sfVector2f){430, 210});
    sfSprite_setPosition(menu->button_settings, (sfVector2f){430, 320});
    sfSprite_setPosition(menu->button_exit, (sfVector2f){430, 430});
}

static void init_menu_background(menu_t *menu)
{
    sfVector2f scale;

    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->background, menu->rect_panel);
    sfSprite_setPosition(menu->background, (sfVector2f){325, 40});
    scale.x = 1.0f;
    scale.y = 1.6f;
    sfSprite_setScale(menu->background, scale);
}

static void setup_menu_elements(menu_t *menu)
{
    init_menu_background(menu);
    init_menu_buttons(menu);
    set_buttons_position(menu);
    init_menu_text(menu);
    center_text(menu->text_play, menu->button_play);
    center_text(menu->text_shop, menu->button_shop);
    center_text(menu->text_settings, menu->button_settings);
    center_text(menu->text_exit, menu->button_exit);
}

menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return NULL;
    menu->texture = sfTexture_createFromFile("assets/sprites/menu/menu.png"
        , NULL);
    menu->click_buffer = sfSoundBuffer_createFromFile("assets/sounds/clic.wav");
    menu->click_sound = sfSound_create();
    sfSound_setBuffer(menu->click_sound, menu->click_buffer);
    menu->rect_panel = (sfIntRect){480, 67, 476, 351};
    menu->rect_button = (sfIntRect){372, 450, 286, 110};
    menu->font = sfFont_createFromFile("assets/fonts/upheaval.ttf");
    setup_menu_elements(menu);
    return menu;
}

int sprite_clicked(sfSprite *sprite, sfRenderWindow *w, sfEvent *ev)
{
    sfFloatRect bounds;
    sfVector2i mp;

    if (ev->type != sfEvtMouseButtonPressed)
        return 0;
    bounds = sfSprite_getGlobalBounds(sprite);
    mp = sfMouse_getPositionRenderWindow(w);
    return sfFloatRect_contains(&bounds, mp.x, mp.y);
}

void menu_destroy(menu_t *menu)
{
    if (!menu)
        return;
    sfSprite_destroy(menu->background);
    sfSprite_destroy(menu->button_play);
    sfSprite_destroy(menu->button_shop);
    sfSprite_destroy(menu->button_settings);
    sfSprite_destroy(menu->button_exit);
    sfTexture_destroy(menu->texture);
    sfFont_destroy(menu->font);
    sfText_destroy(menu->text_play);
    sfText_destroy(menu->text_shop);
    sfText_destroy(menu->text_settings);
    sfText_destroy(menu->text_exit);
    sfSound_destroy(menu->click_sound);
    sfSoundBuffer_destroy(menu->click_buffer);
    free(menu);
}

int update_menu(menu_t *menu, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (sprite_clicked(menu->button_play, window, &event)) {
            sfSound_play(menu->click_sound);
            return 1;
        }
        if (sprite_clicked(menu->button_shop, window, &event)) {
            sfSound_play(menu->click_sound);
            return 2;
        }
        if (sprite_clicked(menu->button_settings, window, &event)) {
            sfSound_play(menu->click_sound);
            return 3;
        }
        if (sprite_clicked(menu->button_exit, window, &event))
            return 4;
    }
    return 0;
}

void menu_draw(menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu->background, NULL);
    sfRenderWindow_drawSprite(window, menu->button_play, NULL);
    sfRenderWindow_drawSprite(window, menu->button_shop, NULL);
    sfRenderWindow_drawSprite(window, menu->button_settings, NULL);
    sfRenderWindow_drawSprite(window, menu->button_exit, NULL);
    sfRenderWindow_drawText(window, menu->text_play, NULL);
    sfRenderWindow_drawText(window, menu->text_shop, NULL);
    sfRenderWindow_drawText(window, menu->text_settings, NULL);
    sfRenderWindow_drawText(window, menu->text_exit, NULL);
}
