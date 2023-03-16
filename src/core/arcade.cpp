/*
** EPITECH PROJECT, 2023
** arcade.cpp
** File description:
** arcade.cpp
*/

#include "arcade.hpp"
#include <stdio.h>

Arcade::Arcade(std::string libname)
{
    _libname = libname;
    std::cout << "Arcade libname: " << _libname << std::endl;
    this->setGameLib(getGameLib());
    this->setGraphicLib(getGraphicLib());
    std::cout << "Game lib: " << std::endl;
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
    void *handle;
    IGame* (*entryGame)();

    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        printf("path: %s\n", i.path().c_str());
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        if (handle) {
            entryGame = (IGame* (*)())dlsym(handle, "entryGame");
            if (entryGame) {
                _gamelib.push_back(i.path());
            } else
                std::cerr << "[GAME] Error: failed to find entry point [entryLib] in " << i.path() << "\n";
            dlclose(handle);
        } else
            std::cerr << "[GAME] Error: failed to load " << i.path() << std::endl;
    }
    return _gamelib;
}

std::vector<std::string> Arcade::getGraphicLib()
{
    void *handle;
    ILib* (*entryLib)();

    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        if (handle) {
            entryLib = (ILib* (*)())dlsym(handle, "entryLib");
            if (entryLib) {
                _graphiclib.push_back(i.path());
            } else {
                std::cerr << "[GRAPHIC] Error: failed to find entry point [entryLib] in " << i.path() << "\n";
            }
            dlclose(handle);
        } else
            std::cerr << "[GRAPHIC] Error: failed to load " << i.path() << std::endl;
    }
    return _graphiclib;
}
