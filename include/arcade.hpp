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
#include <memory>
#include <vector>
#include <filesystem>
#include <dlfcn.h>
#include "../src/graphics/ILib.hpp"
#include "../src/Game/IGame.hpp"
#include "Error.hpp"

class Arcade {
    public:
        enum Key_core {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        QUIT, // quitte le jeu
        PAUSE, // pause
        LIB, // change de lib
        GAME, // change de jeux
        VALID
    };
        Arcade(std::string libname);
        ~Arcade();
        std::string getLibName();
        std::vector<std::string> getGameLib();
        std::vector<std::string> getGraphicLib();
        void addplayername(char c);
        void setGameLib(std::vector<std::string> gamelib);
        void setGraphicLib(std::vector<std::string> graphiclib);
        void LoadLib(std::string &libname);
        void LoadGame(std::string &libname);
        void LoadnextLib();
        void LoadprevLib();
        void LoadnextGame();
        void LoadprevGame();
        void loop();
        void menu();
    private:
        std::vector<std::string> _map;
        std::string _libname;
        std::vector<std::string> _gamelib;
        std::vector<std::string> _graphiclib;
        ILib *_lib;
        std::shared_ptr<IGame> _gameptr;
        std::vector<void *> _handles;
        std::string _playername;
};

#endif /* !ARCADE_HPP_ */
