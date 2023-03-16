/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main
*/

#include "arcade.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        Arcade arcade(av[1]);
        arcade.loop();
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
