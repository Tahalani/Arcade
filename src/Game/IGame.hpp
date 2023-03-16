/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <iostream>
#include <vector>

class IGame {
    public:
        virtual ~IGame();
        virtual void init() = 0;
        virtual void stop() = 0;
};

#endif /* !IGAME_HPP_ */
