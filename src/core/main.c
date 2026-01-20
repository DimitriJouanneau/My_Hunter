/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "../../include/my_hunter.h"
#include "../../include/hud.h"
#include "../../include/menu.h"

void center_text(sfText *text, sfSprite *sprite)
{
    sfFloatRect s = sfSprite_getGlobalBounds(sprite);
    sfFloatRect t = sfText_getLocalBounds(text);
    sfVector2f pos;

    pos.x = s.left + (s.width - t.width) / 2 - t.left;
    pos.y = s.top + (s.height - t.height) / 2 - t.top - 3;
    sfText_setPosition(text, pos);
}

static void h_flag(void)
{
    write(1, "To run the program type: ./my_hunter\n", 37);
    write(1, "The goal of the game is to kill every bird in every wave.\n", 58);
    write(1, "You have a total of 3 lives and can buy some potions ", 53);
    write(1, "in the shop with money earned by killing birds.\n", 48);
}

static int default_resolution(resolution_t *res)
{
    if (!res)
        return 84;
    res->width = 1080;
    res->height = 608;
    res->back = create_background("bg_1080*608.png");
    return 0;
}

static int other_resolution(resolution_t *res, char *arg)
{
    if (my_strcmp(arg, "800") == 0) {
        res->width = 800;
        res->height = 600;
        res->back = create_background("bg_800*600.png");
        return 1;
    }
    if (my_strcmp(arg, "1920") == 0) {
        res->width = 1920;
        res->height = 1080;
        res->back = create_background("bg_1920*1080.png");
        return 1;
    }
    return 84;
}

static void scaling(resolution_t *res)
{
    sfVector2f scale;

    res->scale_x = (float)res->width / 1080.0f;
    res->scale_y = (float)res->height / 608.0f;
    scale.x = res->scale_x;
    scale.y = res->scale_y;
    sfSprite_setScale(res->back, scale);
}

static int process_args(int argc, char **argv, resolution_t *res)
{
    if (argc != 2)
        return 1;
    if (my_strcmp(argv[1], "-h") == 0) {
        h_flag();
        return 0;
    }
    return other_resolution(res, argv[1]);
}

int handle_args(int argc, char **argv, resolution_t *res)
{
    int status;

    if (default_resolution(res) == 84)
        return 84;
    status = process_args(argc, argv, res);
    if (status != 1 && status != 0)
        return 84;
    scaling(res);
    return status == 0 ? 0 : 1;
}

game_context_t init_game(int *screen, resolution_t *res)
{
    sfRenderWindow *window = create_window(res->width, res->height,
        "My Hunter");
    sfCursor *cursor = create_cursor("assets/hud/cursor/red_cursor_50x50.png");
    bird_list_t *birds = init_bird_list();
    wave_t *wave = init_wave();
    menu_t *menu = create_menu();
    hud_t *hud = create_hud();
    sfSprite *background = res->back;
    game_context_t game_context = {window, menu, hud, birds,
        wave, background, screen, *res};

    if (cursor)
        sfRenderWindow_setMouseCursor(window, cursor);
    return game_context;
}

sfMusic *init_global_music(void)
{
    sfMusic *music = sfMusic_createFromFile("assets/sounds/music.ogg");

    if (!music) {
        write(2, "Error loading music\n", 20);
        return NULL;
    }
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

int main(int argc, char **argv)
{
    int screen = 0;
    resolution_t res;
    int ret = handle_args(argc, argv, &res);
    game_context_t game_context;
    sfMusic *music;

    if (ret != 1)
        return ret;
    music = init_global_music();
    if (!music) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
    game_context = init_game(&screen, &res);
    set_framerate(game_context.window, 60);
    start_waves(&game_context, game_context.wave,
        game_context.birds, game_context.hud);
    game_loop(&game_context);
    sfRenderWindow_destroy(game_context.window);
    return 0;
}
