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
    this->setGameLib(getGameLib());
    this->setGraphicLib(getGraphicLib());
}

std::string Arcade::getLibName()
{
    return _libname;
}

Arcade::~Arcade()
{
}

void Arcade::setGameLib(std::vector<std::string> gamelib)
{
    _gamelib = gamelib;
}

void Arcade::setGraphicLib(std::vector<std::string> graphiclib)
{
    _graphiclib = graphiclib;
}

std::vector<std::string> Arcade::getGameLib()
{
    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        std::cout << i.path() << std::endl;
    }
    return _gamelib;
}

std::vector<std::string> Arcade::getGraphicLib()
{
    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        std::cout << i.path() << std::endl;
    }
    return _gamelib;
}
