/*
** EPITECH PROJECT, 2023
** Snake.cpp
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::init()
{
}

void Snake::stop()
{
}

extern "C" {
    IGame *entryGame() {
        return new Snake();
    }
}
