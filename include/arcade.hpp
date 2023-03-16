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

class Arcade {
    public:
        Arcade(std::string libname);
        ~Arcade();
        std::string getLibName();
        std::vector<std::string> getGameLib();
        std::vector<std::string> getGraphicLib();
        void setGameLib(std::vector<std::string> gamelib);
        void setGraphicLib(std::vector<std::string> graphiclib);
    private:
        std::string _libname;
        std::vector<std::string> _gamelib;
        std::vector<std::string> _graphiclib;
};

#endif /* !ARCADE_HPP_ */
