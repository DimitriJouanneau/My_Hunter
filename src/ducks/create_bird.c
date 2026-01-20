/*
** EPITECH PROJECT, 2025
** create_bird.c
** File description:
** create bird
*/

#include "../../include/my_hunter.h"

bird_t *create_bird(const char *filepath, sfVector2f *pos, resolution_t *res)
{
    bird_t *bird = malloc(sizeof(bird_t));

    bird->texture = sfTexture_createFromFile(filepath, NULL);
    if (!bird->texture || !bird)
        return NULL;
    bird->sprite = sfSprite_create();
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    bird->position = *pos;
    sfSprite_setPosition(bird->sprite, *pos);
    bird->rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    sfSprite_setScale(bird->sprite, (sfVector2f){res->scale_x, res->scale_y});
    bird->alive = 1;
    bird->velocity.x = (float)(rand() % 7 - 3);
    bird->velocity.y = (float)(rand() % 7 - 3);
    return bird;
}

void draw_bird(sfRenderWindow *window, bird_t *bird)
{
    if (bird->alive)
        sfRenderWindow_drawSprite(window, bird->sprite, NULL);
}
