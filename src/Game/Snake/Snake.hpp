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
    #include <unordered_map>
    #include <array>
    #include <functional>

static constexpr char GHOST = 'G';
static constexpr char SNAKE = 'O';
static constexpr char WALL = 'X';
static constexpr char COIN = '-';
static constexpr char EMPTY = ' ';
static constexpr int LEFT = 1;
static constexpr int RIGHT = 2;
static constexpr int UP = 3;
static constexpr int DOWN = 4;
static constexpr int ESCAPE = 5;
static constexpr int TIMER_GHOST = 45;
const inline char *GAME_NAME = "Snake";

class Snake : public IGame {
    public:
        Snake();
        ~Snake();
        std::vector<std::string> getMap() const override {return map;};
        void setStatus(bool status);
        std::size_t handleSnake(std::size_t key);
        void setTime();
        double getTime() const {return _time;};
        void moveSnake(std::size_t y, std::size_t x);
        void loose_condition(std::vector<std::string> map, std::size_t y, std::size_t x);
        void eat_apple(std::size_t y, std::size_t x);
        void addSnake_apple(std::size_t y, std::size_t x);
        void restart() override;
        void in_loop(std::size_t key);
        void setClock() {_start = clock();};
        bool getStatus() const override {return _status;};
        void add_apple();
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
        std::unordered_map<char, std::array<u_int8_t, 4>> _rgbmap {
            {WALL, {255, 255, 255, 255}},
            {SNAKE, {255, 255, 0, 255}},
            {COIN, {255, 0, 255, 255}},
            {EMPTY, {0, 0, 0, 255}}
        };
        std::vector<std::string> map = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XOOOO                      X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                          X",
            "X                    -     X",
            "X                          X",
            "X                          X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        };
};

#endif
