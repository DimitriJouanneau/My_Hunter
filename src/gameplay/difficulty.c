/*
** EPITECH PROJECT, 2025
** difficulty.c
** File description:
** difficulty
*/

#include "../../include/my_hunter.h"

float get_wave_difficulty(int wave)
{
    if (wave <= 10)
        return 1.0f * ((float)wave / 5.0f);
    if (wave <= 12)
        return 1.0f - 0.2f * ((float)(wave - 10) / 2.0f);
    if (wave <= 20)
        return 0.8f + 1.2f * ((float)(wave - 12) / 8.0f);
    return 2.0f;
}
