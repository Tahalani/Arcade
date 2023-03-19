/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <dlfcn.h>
#include "../src/graphics/ILib.hpp"
#include "../src/Game/IGame.hpp"
#include "Error.hpp"

class Arcade {
    public:
        Arcade(std::string libname);
        ~Arcade();
        std::string getLibName();
        std::vector<std::string> getGameLib();
        std::vector<std::string> getGraphicLib();
        void setGameLib(std::vector<std::string> gamelib);
        void setGraphicLib(std::vector<std::string> graphiclib);
        void LoadLib(std::string &libname);
        void LoadGame(std::string &libname);
        void LoadnextLib();
        void LoadprevLib();
        void LoadnextGame();
        void LoadprevGame();
        void loop();
    private:
        std::vector<std::string> _map;
        std::string _libname;
        std::vector<std::string> _gamelib;
        std::vector<std::string> _graphiclib;
        IGame *_game;
        ILib *_lib;
        std::vector<void *> _handles;
};

#endif /* !ARCADE_HPP_ */
