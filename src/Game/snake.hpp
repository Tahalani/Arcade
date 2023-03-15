/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

#include "IGame.hpp"

class Snake : public IGame {
    public:
        Snake();
        ~Snake();
        int add_score() { _score += 1; };
    protected:
    private:
        int _score;
        int _status_game;
        int _key;
        int _key_pause;
        int _key_quit;
};

#endif /* !SNAKE_HPP_ */
