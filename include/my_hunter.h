/*
** EPITECH PROJECT, 2025
** my_hunter.h
** File description:
** my_hunter
*/

#ifndef _MY_HUNTER_
    #define _MY_HUNTER_

    #include <SFML/Graphics.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "hud.h"
    #include "menu.h"
    #include "../lib/my/my_printf/my_printf.h"
    #include "../lib/my/my.h"

typedef struct bird_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f velocity;
    int alive;
} bird_t;

typedef struct wave_s {
    int current_waves;
    float difficulty;
    int birds_to_spawn;
    int bullets;
    float timer;
} wave_t;

typedef struct bird_list_s
{
    bird_t **birds;
    int count;
} bird_list_t;

typedef struct resolution_s {
    int width;
    int height;
    float scale_x;
    float scale_y;
    sfSprite *back;
    unsigned int fps;
} resolution_t;

typedef struct game_context_s {
    sfRenderWindow *window;
    menu_t *menu;
    hud_t *hud;
    bird_list_t *birds;
    wave_t *wave;
    sfSprite *background;
    int *screen;
    resolution_t res;
} game_context_t;

typedef struct analyse_events_s {
    sfRenderWindow *window;
    sfEvent *event;
    bird_list_t *list;
    wave_t *wave;
    hud_t *hud;
    float *flash_timer;
} analyse_event_t;

void game_loop(game_context_t *game_context);
void update_birds(bird_list_t *list, sfClock *clock,
    float difficulty, resolution_t *res);
float get_wave_difficulty(int wave);
void restart_game(game_context_t *ctx);
void start_waves(game_context_t *ctx, wave_t *wave,
    bird_list_t *list, hud_t *hud);
void check_wave_end(game_context_t *ctx);
wave_t *init_wave(void);
void draw_birds(sfRenderWindow *window, bird_list_t *list);
void destroy_bird_list(bird_list_t *list);
bird_list_t *init_bird_list(void);
bird_t *create_bird(const char *filepath, sfVector2f *pos, resolution_t *res);
void update_bird(bird_t *bird, float dt);
void draw_bird(sfRenderWindow *window, bird_t *bird);
void destroy_bird(bird_t *bird);
int is_bird_clicked(bird_t *bird, sfVector2i *mouse_pos);
sfRenderWindow *create_window(unsigned int width, unsigned int height
    , char *title);
void set_framerate(sfRenderWindow *window, unsigned int fps);
int analyse_events(analyse_event_t *analyse_event, game_context_t *ctx);
sfSprite *create_background(const char *filepath);
sfCursor *create_cursor(const char *filepath);

#endif /* _MY_HUNTER_ */
