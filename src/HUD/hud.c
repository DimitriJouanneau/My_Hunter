/*
** EPITECH PROJECT, 2025
** hud.c
** File description:
** hud
*/

#include "../../include/hud.h"

void hud_set_wave(hud_t *hud, int wave)
{
    char number[11];
    char buffer[17] = "Wave: ";

    my_int_to_str(wave, number);
    my_strcat(buffer, number);
    sfText_setString(hud->wave_text, buffer);
}

static void update_score_text(hud_t *hud)
{
    char number[11];
    char buffer[18] = "Score: ";

    my_int_to_str(hud->score, number);
    my_strcat(buffer, number);
    sfText_setString(hud->score_text, buffer);
}

static void update_best_score_text(hud_t *hud)
{
    char number[11];
    char final[23] = "Best score: ";

    my_int_to_str(hud->best_score, number);
    my_strcat(final, number);
    sfText_setString(hud->best_score_text, final);
}

static sfText *create_text(const char *initial_string, sfFont *font
    , sfVector2f *position, unsigned int char_size)
{
    sfText *text = sfText_create();

    if (!text)
        return NULL;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, char_size);
    sfText_setPosition(text, *position);
    sfText_setString(text, initial_string);
    return text;
}

static int check_hud(hud_t *hud)
{
    if (!hud->font || !hud->wave_text || !hud->score_text
        || !hud->best_score_text) {
        destroy_life(hud->life);
        sfText_destroy(hud->wave_text);
        sfText_destroy(hud->score_text);
        sfText_destroy(hud->best_score_text);
        sfFont_destroy(hud->font);
        free(hud);
        return 0;
    }
    return 1;
}

hud_t *create_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));
    sfVector2f wave_pos = {200, 6};
    sfVector2f score_pos = {440, 6};
    sfVector2f best_score_pos = {440, 40};
    life_t *life = create_life();

    if (!hud || !life)
        return NULL;
    hud->life = life;
    hud->font = sfFont_createFromFile("assets/fonts/upheaval.ttf");
    hud->score = 0;
    hud->best_score = 0;
    hud->wave_text = create_text("Wave: 1", hud->font, &wave_pos, 40);
    hud->score_text = create_text("Score: 1", hud->font, &score_pos, 40);
    hud->best_score_text = create_text("Best score: 1", hud->font
        , &best_score_pos, 40);
    if (!check_hud(hud))
        return NULL;
    return hud;
}

void update_hud(hud_t *hud)
{
    update_life(hud->life);
    update_score_text(hud);
    update_best_score_text(hud);
}

void draw_hud(sfRenderWindow *w, hud_t *hud)
{
    draw_life(w, hud->life);
    sfRenderWindow_drawText(w, hud->wave_text, NULL);
    sfRenderWindow_drawText(w, hud->score_text, NULL);
    sfRenderWindow_drawText(w, hud->best_score_text, NULL);
}

void destroy_hud(hud_t *hud)
{
    if (!hud)
        return;
    destroy_life(hud->life);
    sfText_destroy(hud->wave_text);
    sfFont_destroy(hud->font);
    sfText_destroy(hud->score_text);
    sfText_destroy(hud->best_score_text);
    free(hud);
}
