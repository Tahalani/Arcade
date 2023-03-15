/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibbler
*/

#include "nibbler.hpp"

int nibbler_sfml(int ac, char **av)
{
    WindowSFML window;

    window.init();
    window.loop();
    return 0;
}
