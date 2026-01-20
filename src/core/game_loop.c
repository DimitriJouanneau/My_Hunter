/*
** EPITECH PROJECT, 2025
** game_loop.c
** File description:
** game loop
*/

#include "../../include/my_hunter.h"
#include "../../include/hud.h"
#include "../../include/menu.h"

static void draw_game(game_frame_t *frame, bird_list_t *birds)
{
    sfRenderWindow_clear(frame->window, *frame->bg_color);
    sfRenderWindow_drawSprite(frame->window, frame->background, NULL);
    draw_birds(frame->window, birds);
    draw_hud(frame->window, frame->hud);
    sfRenderWindow_display(frame->window);
}

static void draw_menu_screen(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfTransparent);
    menu_draw(menu, window);
    sfRenderWindow_display(window);
}

static int handle_menu(game_context_t *ctx)
{
    int check_button = update_menu(ctx->menu, ctx->window);

    if (check_button == 1)
        *ctx->screen = 1;
    if (check_button == 4)
        return 1;
    draw_menu_screen(ctx->window, ctx->menu);
    return 0;
}

static void update_flash(flash_t *flash)
{
    float dt = sfClock_restart(flash->clock).microseconds / 1000000.0f;

    if (*flash->flash_timer > 0.0f)
        *flash->flash_timer -= dt;
    if (*flash->flash_timer > 0.0f)
        *flash->bg_color = flash->flash_color;
    else
        *flash->bg_color = *flash->normal_color;
}

static int process_events(game_context_t *ctx, sfEvent *event, float *timer)
{
    analyse_event_t ev = {
        ctx->window,
        event,
        ctx->birds,
        ctx->wave,
        ctx->hud,
        timer
    };

    return analyse_events(&ev, ctx);
}

static void frame(game_context_t *ctx, sfClock *clock,
    float *flash_timer, sfClock *flash_clock)
{
    sfColor bg_color;
    flash_t f = {&bg_color, sfRed, &sfBlack, flash_timer, flash_clock};
    game_frame_t frame_struct = {ctx->window, ctx->background
        , ctx->hud, &bg_color};
    bird_list_t birds;

    update_hud(ctx->hud);
    update_birds(ctx->birds, clock, ctx->wave->difficulty, &ctx->res);
    update_flash(&f);
    check_wave_end(ctx);
    draw_game(&frame_struct, ctx->birds);
}

void game_loop(game_context_t *game_context)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfClock *flash_clock = sfClock_create();
    sfColor bg_color;
    float flash_timer = 0.0f;

    while (sfRenderWindow_isOpen(game_context->window)) {
        if (*game_context->screen == 0) {
            if (handle_menu(game_context))
                break;
            continue;
        }
        if (process_events(game_context, &event, &flash_timer))
            break;
        frame(game_context, clock, &flash_timer, flash_clock);
    }
    sfClock_destroy(clock);
    sfClock_destroy(flash_clock);
}
