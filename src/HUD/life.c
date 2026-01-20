/*
** EPITECH PROJECT, 2025
** life.c
** File description:
** life
*/

#include "../../include/hud.h"

life_t *create_life(void)
{
    int i = 0;
    life_t *life = malloc(sizeof(life_t));

    life->life = 3;
    life->max_life = 3;
    life->heart_texture = sfTexture_createFromFile("assets/hud/life/heart.png",
        NULL);
    if (!life->heart_texture) {
        write(2, "Error: can't load heart texture\n", 32);
        return NULL;
    }
    for (i = 0; i < 3; i++) {
        life->hearts[i] = sfSprite_create();
        sfSprite_setTexture(life->hearts[i], life->heart_texture, sfTrue);
        sfSprite_setPosition(life->hearts[i], (sfVector2f){20 + (i * 40), 20});
    }
    return life;
}

void update_life(life_t *life)
{
    int i = 0;

    for (i = 0; i < life->max_life; i++) {
        if (i < life->life)
            sfSprite_setColor(life->hearts[i], sfWhite);
        else
            sfSprite_setColor(life->hearts[i], sfColor_fromRGB(120, 120, 120));
    }
}

void draw_life(sfRenderWindow *w, life_t *life)
{
    for (int i = 0; i < life->max_life; i++)
        sfRenderWindow_drawSprite(w, life->hearts[i], NULL);
}

void destroy_life(life_t *life)
{
    for (int i = 0; i < life->max_life; i++)
        sfSprite_destroy(life->hearts[i]);
    sfTexture_destroy(life->heart_texture);
    free(life);
}
