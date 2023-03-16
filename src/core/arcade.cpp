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
    for (auto &i : _gamelib)
        std::cout << i << std::endl;
    std::cout << "Graphic lib: " << std::endl;
    for (auto &i : _graphiclib)
        std::cout << i << std::endl;
}

ILib *Arcade::LoadLib(std::string &libname)
{
    void *handle;
    ILib* (*entryLib)();
    ILib *lib = nullptr;

    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (handle) {
        entryLib = (ILib* (*)())dlsym(handle, "entryLib");
        if (entryLib)
            lib = entryLib();
        dlclose(handle);
    } else
        std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
    return lib;
}

IGame *Arcade::LoadGame(std::string &libname)
{
    void *handle;
    IGame* (*entryGame)();
    IGame *game = nullptr;

    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (handle) {
        entryGame = (IGame* (*)())dlsym(handle, "entryGame");
        if (entryGame)
            game = entryGame();
        dlclose(handle);
    } else
        std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
    return game;
}

void Arcade::loop()
{
    _lib = LoadLib(_libname);
    std::string game_name = "lib/arcade_snake.so";
    _game = LoadGame(game_name);
    if (_lib && _game)
        std::cout << "Lib and Game loaded" << std::endl;
    else
        throw Error("Lib or Game not loaded");
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
    char *error = nullptr;

    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        printf("path: %s\n", i.path().c_str());
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        error = dlerror();
        if (handle) {
            entryGame = (IGame* (*)())dlsym(handle, "entryGame");
            if (entryGame) {
                _gamelib.push_back(i.path());
            }
            dlclose(handle);
        } else {
            // std::cerr << "[GAME] Error: failed to load " << i.path() << std::endl;
            std::cerr << error << std::endl;
       }
    }
    return _gamelib;
}

std::vector<std::string> Arcade::getGraphicLib()
{
    void *handle;
    ILib* (*entryLib)();
    char *error = nullptr;

    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        if (handle) {
            entryLib = (ILib* (*)())dlsym(handle, "entryLib");
            if (entryLib) {
                _graphiclib.push_back(i.path());
            }
            dlclose(handle);
        } else
            std::cerr << error << std::endl;
    }
    return _graphiclib;
}
