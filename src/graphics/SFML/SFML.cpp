/*
** EPITECH PROJECT, 2023
** sfml.cpp
** File description:
** sfml.cpp
*/

#include "sfml_lib.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}

void SFML::init()
{
}

void SFML::stop()
{
}

extern "C" {
    ILib *entryLib() {
        return new SFML();
    }
}