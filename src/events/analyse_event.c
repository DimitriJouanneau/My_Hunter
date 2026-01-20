/*
** EPITECH PROJECT, 2025
** analyse_event.c
** File description:
** analyse event
*/

#include "../../include/my_hunter.h"
#include "../../include/hud.h"

static void update_score(hud_t *hud, int points)
{
    hud->score += points;
    if (hud->score > hud->best_score)
        hud->best_score = hud->score;
}

static int handle_bird_clicks(bird_list_t *list, sfVector2i *mouse_pos
    , hud_t *hud)
{
    int hit = 0;
    int i = 0;

    for (i = 0; i < list->count; i++) {
        if (list->birds[i]->alive &&
            is_bird_clicked(list->birds[i], mouse_pos)) {
            list->birds[i]->alive = 0;
            hit = 1;
            update_score(hud, 100);
        }
    }
    return hit;
}

static void handle_miss(hud_t *hud, float *flash_timer)
{
    if (hud->life->life > 0)
        hud->life->life--;
    *flash_timer = 0.2f;
}

static void check_end_conditions(game_context_t *ctx)
{
    if (!ctx->wave || !ctx->hud)
        return;
    restart_game(ctx);
    if (ctx->hud->life)
        ctx->hud->life->life = ctx->hud->life->max_life;
}

static int handle_mouse_click(analyse_event_t *analyse_event,
    game_context_t *ctx)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(analyse_event->window);
    int hit;

    analyse_event->wave->bullets--;
    hit = handle_bird_clicks(analyse_event->list, &pos, analyse_event->hud);
    if (!hit)
        handle_miss(analyse_event->hud, analyse_event->flash_timer);
    if (analyse_event->wave->bullets <= 0 ||
        analyse_event->hud->life->life <= 0) {
        check_wave_end(ctx);
        return 2;
    }
    return 0;
}

static int handle_click(analyse_event_t *ae, game_context_t *ctx)
{
    int result;

    if (ae->event->mouseButton.button != sfMouseLeft)
        return 0;
    result = handle_mouse_click(ae, ctx);
    if (result == 1)
        return 1;
    if (result == 2)
        return 0;
    return 0;
}

int analyse_events(analyse_event_t *analyse_event, game_context_t *ctx)
{
    int i = 0;

    while (sfRenderWindow_pollEvent(analyse_event->window,
            analyse_event->event)) {
        if (analyse_event->event->type == sfEvtClosed) {
            sfRenderWindow_close(analyse_event->window);
            return 1;
        }
        if (analyse_event->event->type == sfEvtMouseButtonPressed)
            return handle_click(analyse_event, ctx);
    }
    return 0;
}
