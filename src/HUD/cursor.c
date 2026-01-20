/*
** EPITECH PROJECT, 2025
** cursor.c
** File description:
** cursor
*/

#include "../../include/my_hunter.h"

sfCursor *create_cursor(const char *filepath)
{
    sfImage *new_cursor = sfImage_createFromFile(filepath);
    sfVector2u size;
    const sfUint8 *pixels;
    sfVector2u hotspot;
    sfCursor *cursor;

    if (!new_cursor)
        return NULL;
    size = sfImage_getSize(new_cursor);
    pixels = sfImage_getPixelsPtr(new_cursor);
    hotspot.x = size.x / 2;
    hotspot.y = size.y / 2;
    cursor = sfCursor_createFromPixels(pixels, size, hotspot);
    sfImage_destroy(new_cursor);
    return cursor;
}
