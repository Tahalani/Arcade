/*
** EPITECH PROJECT, 2023
** Snake.hpp
** File description:
** Snake.hpp
*/

#ifndef SNAKE_HPP
    #define SNAKE_HPP

    #include "../IGame.hpp"
    #include <math.h>
    #include <map>
    #include <functional>

#define SNAKE 'O'
#define WALL 'X'
#define COIN '-'
#define EMPTY ' '
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define GAME_NAME "Snake"

class Snake : public IGame {
    public:
        Snake();
        ~Snake();
        std::vector<std::string> getMap() const override {return map;};
        void run_game(std::size_t key);
        std::size_t handleSnake(std::size_t key, std::vector<std::string> &map);
        void setTime();
        double getTime() const {return _time;};
        std::vector<std::string> moveSnake(std::size_t y, std::size_t x);
        void loose_condition(std::vector<std::string> map, std::size_t y, std::size_t x);
        void eat_apple(std::vector<std::string> map, std::size_t y, std::size_t x);
        std::vector<std::string> addSnake_apple(std::vector<std::string>, std::size_t y, std::size_t x);
        void restart() override;
        void in_loop(std::size_t key);
        void setClock() {_start = clock();};
        bool getStatus() const override {return _status;};
        void runGame(std::size_t key) override;
    private:
        std::map<std::size_t, std::pair<std::size_t, std::size_t>>  _coord;
        bool _is_loose;
        bool _is_apple;
        double _sink;
        double _time;
        double _time_ghost;
        bool _status;
        clock_t _start;
        std::vector<std::string> map = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XOOOO -                    X",
            "X                          X",
            "X    -               -     X",
            "X                          X",
            "X         -                X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X           -              X",
            "X                          X",
            "X                          X",
            "X                     -    X",
            "X                          X",
            "X                          X",
            "X    -                     X",
            "X                          X",
            "X                          X",
            "X             -            X",
            "X                      -   X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X        -                 X",
            "X                    -     X",
            "X                          X",
            "X                          X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        };
};

#endif
