/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "WindowSFML.hpp"

std::vector<std::string> map = {
    "XXXXXXXXXXXXXXXXXXXX"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X                  X"
    "X       X xxxx     X"
    "X       X x  x     X"
    "X       X x  x     X"
    "X XXXXXXX XXXX     X"
    "X                  X"
    "XXXXXXXXXXXXXXXXXXXX"
};


class Nibbler {
    public:
        Nibbler();
        ~Nibbler();
    protected:
    private:
        int _score;
        int _pos_x;
        int _pos_y;
        int _direction;
};

#endif /* !NIBBLER_HPP_ */
