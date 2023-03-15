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

std::vector<std::string> map = {
    "XXXXXXXXXXXXXXXXXXXX"
    "X                  X"
    "X XXXXX X X XXXXXX X"
    "X     X X X XXXXXX X"
    "X X X X X X        X"
    "X X X X X X  XXXXX X"
    "X X X X X XX X   X X"
    "X X X      X X   X X"
    "X X XXXXXX X XXXXX X"
    "X X                X"
    "X XXXXXXX XXXX XXX X"
    "X         X  X X X X"
    "X XXXXXXX XXXX X X X"
    "X              XXX X"
    "X XXXXXXX xxxx     X"
    "X X     X x  x XXX X"
    "X X     X x  x X X X"
    "X XXXXXXX XXXX XXX X"
    "X                  X"
    "XXXXXXXXXXXXXXXXXXXX"
};

class IGame {
    public:
        virtual ~IGame();
        virtual void start_game() = 0;
        virtual void stop_game() = 0;
        virtual void restart_game() = 0;
        virtual void get_score() = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */
