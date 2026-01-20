/*
** EPITECH PROJECT, 2025
** update_birds.c
** File description:
** update birds
*/

#include "../../include/my_hunter.h"

static void update_bird_animation(bird_t *b)
{
    b->rect.left += 110;
    if (b->rect.left >= 110 * 3)
        b->rect.left = 0;
    sfSprite_setTextureRect(b->sprite, b->rect);
}

static void update_bird_position(bird_t *b, float difficulty, resolution_t *res)
{
    b->position.x += b->velocity.x * difficulty * 4 * res->scale_x;
    b->position.y += b->velocity.y * difficulty * 4 * res->scale_y;
    if (b->position.x < 0 || b->position.x > res->width - 110 * res->scale_x)
        b->velocity.x *= -1;
    if (b->position.y < 0 || b->position.y > res->height - 110 * res->scale_y)
        b->velocity.y *= -1;
    sfSprite_setPosition(b->sprite, b->position);
}

void update_birds(bird_list_t *list, sfClock *clock,
    float difficulty, resolution_t *res)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0f;
    game_context_t *ctx;

    if (seconds < 0.1f)
        return;
    for (int i = 0; i < list->count; i++) {
        update_bird_animation(list->birds[i]);
        update_bird_position(list->birds[i], difficulty, res);
    }
    sfClock_restart(clock);
}
