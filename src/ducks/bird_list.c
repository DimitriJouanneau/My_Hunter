/*
** EPITECH PROJECT, 2025
** bird
** File description:
** bird
*/

#include "../../include/my_hunter.h"

bird_list_t *init_bird_list(void)
{
    bird_list_t *list = malloc(sizeof(bird_list_t));

    list->birds = NULL;
    list->count = 0;
    return list;
}

void destroy_bird_list(bird_list_t *list)
{
    if (!list)
        return;
    for (int i = 0; i < list->count; i++) {
        if (list->birds[i]) {
            destroy_bird(list->birds[i]);
        }
    }
    free(list->birds);
    free(list);
}

void draw_birds(sfRenderWindow *window, bird_list_t *list)
{
    int i = 0;

    for (i = 0; i < list->count; i++)
        if (list->birds[i]->alive)
            sfRenderWindow_drawSprite(window, list->birds[i]->sprite, NULL);
}
