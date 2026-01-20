/*
** EPITECH PROJECT, 2025
** loop.c
** File description:
** loop
*/

#include "../../include/my_hunter.h"

void check_wave_end(game_context_t *ctx)
{
    int alive = 0;
    int i = 0;

    if (ctx->hud && ctx->hud->life && ctx->hud->life->life <= 0) {
        ctx->hud->life->life = ctx->hud->life->max_life;
        ctx->hud->score = 0;
        ctx->wave->current_waves = 1;
        restart_game(ctx);
        return;
    }
    for (i = 0; i < ctx->birds->count; i++) {
        if (ctx->birds->birds[i] && ctx->birds->birds[i]->alive)
            alive++;
    }
    if (alive == 0) {
        ctx->wave->current_waves++;
        start_waves(ctx, ctx->wave, ctx->birds, ctx->hud);
    }
}
