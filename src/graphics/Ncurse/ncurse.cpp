/*
** EPITECH PROJECT, 2023
** ncurse.cpp
** File description:
** ncurse.cpp
*/

#include "ncurse_lib.hpp"

Ncurse::Ncurse()
{
}

Ncurse::~Ncurse()
{
}

void Ncurse::init()
{
}

void Ncurse::stop()
{
}

extern "C" {
    ILib *entryLib() {
        return new Ncurse();
    }
}
