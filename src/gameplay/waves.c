/*
** EPITECH PROJECT, 2025
** waves.c
** File description:
** waves
*/

#include "../../include/my_hunter.h"

wave_t *init_wave(void)
{
    wave_t *wave = malloc(sizeof(wave_t));

    if (!wave)
        return NULL;
    wave->current_waves = 1;
    wave->difficulty = 1.0f;
    wave->birds_to_spawn = 0;
    wave->bullets = 0;
    return wave;
}

static void wave_data(wave_t *wave)
{
    int is_boss = (wave->current_waves == 10 || wave->current_waves == 20);
    int base_birds = 5;

    wave->difficulty = get_wave_difficulty(wave->current_waves);
    wave->birds_to_spawn = (int)base_birds * wave->difficulty;
    if (wave->birds_to_spawn < 1)
        wave->birds_to_spawn = 5;
    if (is_boss)
        wave->birds_to_spawn *= 3;
    wave->bullets = wave->birds_to_spawn + 1;
}

static void allocate_bird(bird_list_t *list, int count)
{
    list->count = count;
    list->birds = malloc(sizeof(bird_t *) * count);
}

static sfVector2f bird_position(int index, int total)
{
    sfVector2f pos;
    int width = 1080 - 110 - 50;

    pos.x = 50.0f + index * (width / total);
    pos.y = 50 + rand() % (608 - 160);
    return pos;
}

void start_waves(game_context_t *ctx, wave_t *wave, bird_list_t *list,
    hud_t *hud)
{
    int i = 0;
    sfVector2f pos;

    wave_data(wave);
    if (list->birds != NULL) {
        for (int i = 0; i < list->count; i++)
            destroy_bird(list->birds[i]);
        free(list->birds);
    }
    list->count = 0;
    list->count = wave->birds_to_spawn;
    list->birds = malloc(sizeof(bird_t *) * list->count);
    for (i = 0; i < list->count; i++) {
        pos = bird_position(i, list->count);
        list->birds[i] = create_bird("assets/sprites/birds/bird.png", &pos,
            &ctx->res);
    }
    if (hud)
        hud_set_wave(hud, wave->current_waves);
}

void restart_game(game_context_t *ctx)
{
    ctx->wave->current_waves = 1;
    start_waves(ctx, ctx->wave, ctx->birds, ctx->hud);
}
