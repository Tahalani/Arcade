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
#include <string>
#include <unordered_map>

#ifndef KEY_HPP_
    #define KEY_HPP_
        enum Key {
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
#endif /* !KEY_HPP_ */

class IGame {
    public:
        virtual ~IGame() = default;
        virtual std::vector<std::string> getMap() const = 0;
        virtual void runGame(std::size_t key) = 0;
        virtual bool getStatus() const = 0;
        virtual void restart() = 0;
        virtual std::unordered_map<char, std::array<u_int8_t, 4>> getRgbValues() const = 0;
};

#endif /* !IGAME_HPP_ */
