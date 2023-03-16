/*
** EPITECH PROJECT, 2023
** sdl.cpp
** File description:
** sdl.cpp
*/

#include "sdl_lib.hpp"

SDL::SDL()
{
}

SDL::~SDL()
{
}

void SDL::init()
{
}

void SDL::stop()
{
}

extern "C" {
    ILib *entryLib() {
        return new SDL();
    }
}