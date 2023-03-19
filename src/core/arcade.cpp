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
    this->setGameLib(getGameLib());
    this->setGraphicLib(getGraphicLib());
    _game = nullptr;
    _lib = nullptr;
    std::cout << "Game lib: " << std::endl;
    for (auto &i : _gamelib)
        std::cout << i << std::endl;
    std::cout << "Graphic lib: " << std::endl;
    for (auto &i : _graphiclib)
        std::cout << i << std::endl;
}

void Arcade::LoadLib(std::string &libname)
{
    void *handle;
    ILib* (*entryLib)();

    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (handle) {
        entryLib = (ILib* (*)())dlsym(handle, "entryLib");
        if (entryLib) {
            _lib = entryLib();
            _handles.push_back(handle);
        }
        // else
            // dlclose(handle);
    } else
        std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
}

void Arcade::LoadGame(std::string &libname)
{
    void *handle;
    IGame* (*entryGame)();

    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (handle) {
        entryGame = (IGame* (*)())dlsym(handle, "entryGame");
        if (entryGame) {
            _game = entryGame();
            _handles.push_back(handle);
        }
        // else
            // dlclose(handle);
    } else
        std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
}

void Arcade::loop()
{
    if (_gamelib.empty())
        throw Error("No game lib found");
    LoadLib(_libname);
    LoadGame(_gamelib.front());
    if (_lib && _game)
        std::cout << "Lib and Game loaded" << std::endl;
    else
        throw Error("Lib or Game not loaded");
    _graphiclib.insert(_graphiclib.begin(), _libname);
    auto begin = _graphiclib.begin();
    for (auto it = _graphiclib.end(); it != begin; --it) {
        if (*it == _libname) {
            _graphiclib.erase(it);
            break;
        }
    }
    _map = _game->getMap();
    int key = 0;

    while (_game->getStatus() == true) {
        _lib->displayMap(_map);
        key = _lib->handleEvent();
        _game->runGame(key);
        _map = _game->getMap();
        if (key == ENTER)
            LoadnextLib();
        if (key == SPACE) {
            LoadnextGame();
            key = 0;
        }
    }
    delete _lib;
    delete _game;
}

std::string Arcade::getLibName()
{
    return _libname;
}

Arcade::~Arcade()
{
    for (auto &i : _handles)
        dlclose(i);
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
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        error = dlerror();
        if (handle) {
            entryGame = (IGame* (*)())dlsym(handle, "entryGame");
            if (entryGame) {
                _gamelib.push_back(i.path());
            }
            // dlclose(handle);
        } else {
            std::cerr << error << std::endl;
       }
    }
    free(error);
    return _gamelib;
}

std::vector<std::string> Arcade::getGraphicLib()
{
    void *handle;
    ILib* (*entryLib)();
    char *error = nullptr;

    for (auto &i : std::filesystem::directory_iterator("./lib/")) {
        handle = dlopen(i.path().c_str(), RTLD_LAZY);
        error = dlerror();
        if (handle) {
            entryLib = (ILib* (*)())dlsym(handle, "entryLib");
            if (entryLib) {
                _graphiclib.push_back(i.path());
            }
            // dlclose(handle);
        } else
            std::cerr << error << std::endl;
    }
    free(error);
    return _graphiclib;
}

void Arcade::LoadnextLib()
{
    delete _lib;
    _graphiclib.emplace_back(_graphiclib.front());
    _graphiclib.erase(_graphiclib.begin());
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    LoadLib(_graphiclib.front());
}

void Arcade::LoadnextGame()
{
    delete _game;
    _gamelib.emplace_back(_gamelib.front());
    _gamelib.erase(_gamelib.begin());
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    LoadGame(_gamelib.front());
}

void Arcade::LoadprevLib()
{
    delete _lib;
    _graphiclib.insert(_graphiclib.begin(), _graphiclib.back());
    _graphiclib.pop_back();
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    LoadLib(_graphiclib.front());
}

void Arcade::LoadprevGame()
{
    delete _game;
    _gamelib.insert(_gamelib.begin(), _gamelib.back());
    _gamelib.pop_back();
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    LoadGame(_gamelib.front());
}
