/*
** EPITECH PROJECT, 2023
** arcade.cpp
** File description:
** arcade.cpp
*/

#include "arcade.hpp"
#include <algorithm>

Arcade::Arcade(std::string libname) : _libname(libname)
{
    this->getGameLib();
    this->getGraphicLib();
    std::cout << "Game lib: " << std::endl;
    for (auto &i : _gamelib)
        std::cout << i << std::endl;
    std::cout << "Graphic lib: " << std::endl;
    for (auto &i : _graphiclib)
        std::cout << i << std::endl;
}

void Arcade::addplayername(char c)
{
    if (c >= 'A' && c <= 'Z')
        _playername += c;
}

void Arcade::menu()
{
    int key2 = 0;
    while (1) {
        this->getGameLib();
        this->getGraphicLib();
        std::string tmp_lib = _graphiclib.front();
        std::string tmp_game = _gamelib.front();
        tmp_lib.erase(0, 13);
        tmp_lib.erase(tmp_lib.size() - 3, 3);
        tmp_game.erase(0, 13);
        tmp_game.erase(tmp_game.size() - 3, 3);
        key2 = _lib.getLib()->handleEvent();
        _lib.getLib()->drawText("ARCADE", {1920 / 2 - 200, 100}, 60);
        _lib.getLib()->drawText("Enter a name : " + _playername, {1920 / 2 - 20, 200}, 60);
        _lib.getLib()->drawText("Choose a game : (Press Space to Change)", {0, 300}, 60);
        _lib.getLib()->drawText("< " + tmp_game + " >", {0, 350}, 60);
        _lib.getLib()->drawText("Choose a graphic lib : (Press Enter to Change)", {0, 600}, 60);
        _lib.getLib()->drawText("< " + tmp_lib + " >", {0, 650}, 60);
        _lib.getLib()->drawText("Press P to valid", {0, 900}, 60);
        _lib.getLib()->menu();
        if (key2 == QUIT) {
            std::cout << "Quit" << std::endl;
            // delete _lib;
            return;
        }
        if (key2 == LIB) {
            _graphiclib.emplace_back(_graphiclib.front());
            _graphiclib.erase(_graphiclib.begin());
        }
        if (key2 == GAME) {
            _gamelib.emplace_back(_gamelib.front());
            _gamelib.erase(_gamelib.begin());
        }
        if (key2 == VALID) {
            break;
        }
        addplayername(key2);
    }
    // delete _lib;
    try {
        _lib.LoadLib(_graphiclib.front(), "Lib");
        _game.LoadLib(_gamelib.front(), "Game");
    } catch (Loader<ILib>::ErrorParser &e) {
        throw Error("Lib not loaded");
    } catch (Loader<IGame>::ErrorParser &e) {
        throw Error("Game not loaded");
    }
}

void Arcade::loop()
{
    if (_gamelib.empty())
        throw Error("No game lib found");
    try {
        _lib.LoadLib(_libname, "Lib");
    } catch (Loader<ILib>::ErrorParser &e) {
        throw Error("Lib not loaded");
    }
    _graphiclib.insert(_graphiclib.begin(), _libname);
    auto end = _graphiclib.end();
    for (auto it = _graphiclib.begin(); it != end; ++it) {
        if (*it == _libname) {
            _graphiclib.erase(it);
            break;
        }
    }
    this->menu();
    if (_game.getLib() == nullptr) {
        return;
    }
    _map = _game.getLib()->getMap();
    int key = 0;
    while (_game.getLib()->getStatus() == true) {
        this->getGameLib();
        this->getGraphicLib();
        _lib.getLib()->displayMap(_map, _game.getLib()->getScore(), _game.getLib()->getRgbValues());
        key = _lib.getLib()->handleEvent();
        _game.getLib()->runGame(key);
        _map = _game.getLib()->getMap();
        if (key == LIB)
            LoadnextLib();
        if (key == GAME) {
            LoadnextGame();
            key = 0;
        }
        if (key == RESET) {
            _game.getLib()->restart();
        }
    }
    // delete _lib;
    // delete _game;
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

void Arcade::getGameLib()
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
                if ((std::find(_gamelib.begin(), _gamelib.end(), i.path()) == _gamelib.end()))
                    _gamelib.push_back(i.path());
                dlclose(handle);
            }
        }
    }
    if (error != nullptr)
        free(error);
}

void Arcade::getGraphicLib()
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
                if ((std::find(_graphiclib.begin(), _graphiclib.end(), i.path()) == _graphiclib.end())) {
                    _graphiclib.push_back(i.path());
                }
                dlclose(handle);
            }
        }
    }
    if (error != nullptr)
        free(error);
}

void Arcade::LoadnextLib()
{
    // delete _lib;
    _graphiclib.emplace_back(_graphiclib.front());
    _graphiclib.erase(_graphiclib.begin());
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    try {
        _lib.LoadLib(_graphiclib.front(), "Lib");
    } catch (Loader<ILib>::ErrorParser &e) {
        throw Error("Cannot Load next Lib");
    }
}

void Arcade::LoadnextGame()
{
    // delete _game;
    _gamelib.emplace_back(_gamelib.front());
    _gamelib.erase(_gamelib.begin());
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    try {
        _game.LoadLib(_gamelib.front(), "Game");
    } catch (Loader<IGame>::ErrorParser &e) {
        throw Error("Cannot Load next Game");
    }
}

void Arcade::LoadprevLib()
{
    // delete _lib;
    _graphiclib.insert(_graphiclib.begin(), _graphiclib.back());
    _graphiclib.pop_back();
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    try {
    _lib.LoadLib(_graphiclib.front(), "Lib");
    } catch (Loader<ILib>::ErrorParser &e) {
        throw Error("Cannot Load prev Lib");
    }
}

void Arcade::LoadprevGame()
{
    // delete _game;
    _gamelib.insert(_gamelib.begin(), _gamelib.back());
    _gamelib.pop_back();
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    try {
        _game.LoadLib(_gamelib.front(), "Game");
    } catch (Loader<IGame>::ErrorParser &e) {
        throw Error("Cannot Load prev Game");
    }
}
