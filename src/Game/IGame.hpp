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

class IGame {
    public:
        virtual ~IGame() = default;
        virtual std::vector<std::string> getMap() const = 0;
        virtual void runGame(std::size_t key) = 0;
        virtual bool getStatus() const = 0;
        virtual void restart() = 0;
};

#endif /* !IGAME_HPP_ */
