/*
** EPITECH PROJECT, 2025
** hud.h
** File description:
** header file
*/

#ifndef _HUD_H_
    #define _HUD_H_

    #include <SFML/Graphics.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "../lib/my/my_printf/my_printf.h"
    #include "../lib/my/my.h"

typedef struct life_s {
    int life;
    int max_life;
    sfSprite *hearts[3];
    sfTexture *heart_texture;
} life_t;

typedef struct hud_s {
    life_t *life;
    sfText *wave_text;
    sfFont *font;
    sfTexture *wave_back;
    int score;
    int best_score;
    sfText *score_text;
    sfText *best_score_text;
} hud_t;

typedef struct flash_s {
    sfColor *bg_color;
    sfColor flash_color;
    sfColor *normal_color;
    float *flash_timer;
    sfClock *clock;
} flash_t;

typedef struct game_frame_s {
    sfRenderWindow *window;
    sfSprite *background;
    hud_t *hud;
    sfColor *bg_color;
} game_frame_t;

void hud_set_wave(hud_t *hud, int wave);

hud_t *create_hud(void);
void update_hud(hud_t *hud);
void draw_hud(sfRenderWindow *window, hud_t *hud);
void destroy_hud(hud_t *hud);

life_t *create_life(void);
void update_life(life_t *life);
void draw_life(sfRenderWindow *w, life_t *life);
void destroy_life(life_t *life);


#endif /* _HUD_H_ */
