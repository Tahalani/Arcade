/*
** EPITECH PROJECT, 2023
** arcade.cpp
** File description:
** arcade.cpp
*/

#include "arcade.hpp"

Arcade::Arcade(std::string libname) : _libname(libname)
{
    this->setGameLib(getGameLib());
    this->setGraphicLib(getGraphicLib());
    // _lib = nullptr;
    // _gameptr = nullptr;
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

// void Arcade::LoadLib(std::string &libname)
// {
//     void *handle;
//     ILib* (*entryLib)();

//     handle = dlopen(libname.c_str(), RTLD_LAZY);
//     if (handle) {
//         entryLib = (ILib* (*)())dlsym(handle, "entryLib");
//         if (entryLib) {
//             _lib = entryLib();
//             _handles.push_back(handle);
//         }
//         // else
//             // dlclose(handle);
//     } else
//         std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
// }

// void Arcade::LoadGame(std::string &libname)
// {
//     void *handle;
//     IGame* (*entryGame)();

//     handle = dlopen(libname.c_str(), RTLD_LAZY);
//     if (handle) {
//         entryGame = (IGame* (*)())dlsym(handle, "entryGame");
//         if (entryGame) {
//             // _game = entryGame();
//             _gameptr = std::shared_ptr<IGame>(entryGame());
//             _handles.push_back(handle);
//         }
//         // else
//             // dlclose(handle);
//     } else
//         std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
// }

void Arcade::menu()
{
    int key2 = 0;
    while (1) {
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
        // std::cerr << e.what() << std::endl;
        throw Error("Lib not loaded");
    }
    // LoadLib(_libname);
    // if (_lib)
    //     std::cout << "Lib loaded" << std::endl;
    // else
    //     throw Error("Lib not loaded");
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
    // if (_gameptr)
    //     std::cout << "Lib and Game loaded" << std::endl;
    // else
    //     throw Error("Lib or Game not loaded");
    _map = _game.getLib()->getMap();
    int key = 0;
    while (_game.getLib()->getStatus() == true) {
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
                dlclose(handle);
            }
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
                dlclose(handle);
            }
        } else
            std::cerr << error << std::endl;
    }
    free(error);
    return _graphiclib;
}

void Arcade::LoadnextLib()
{
    // delete _lib;
    _graphiclib.emplace_back(_graphiclib.front());
    _graphiclib.erase(_graphiclib.begin());
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    _lib.LoadLib(_graphiclib.front(), "Lib");
}

void Arcade::LoadnextGame()
{
    // delete _game;
    _gamelib.emplace_back(_gamelib.front());
    _gamelib.erase(_gamelib.begin());
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    _game.LoadLib(_gamelib.front(), "Game");
}

void Arcade::LoadprevLib()
{
    // delete _lib;
    _graphiclib.insert(_graphiclib.begin(), _graphiclib.back());
    _graphiclib.pop_back();
    std ::cout << "newlib: " << _graphiclib.front() << std::endl;
    _lib.LoadLib(_graphiclib.front(), "Lib");
}

void Arcade::LoadprevGame()
{
    // delete _game;
    _gamelib.insert(_gamelib.begin(), _gamelib.back());
    _gamelib.pop_back();
    std ::cout << "newgame: " << _gamelib.front() << std::endl;
    _game.LoadLib(_gamelib.front(), "Game");
}
