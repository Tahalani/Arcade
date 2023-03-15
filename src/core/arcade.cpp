/*
** EPITECH PROJECT, 2023
** arcade.cpp
** File description:
** arcade.cpp
*/

#include "arcade.hpp"

Arcade::Arcade(std::string libname)
{
    _libname = libname;
    std::cout << "Arcade libname: " << _libname << std::endl;
}

std::string Arcade::getLibName()
{
    return _libname;
}

Arcade::~Arcade()
{
}

