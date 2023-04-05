/*
** EPITECH PROJECT, 2023
** Snake.hpp
** File description:
** Snake.hpp
*/

#ifndef NIBBLER_HPP
    #define NIBBLER_HPP

    #include "../IGame.hpp"
    #include <math.h>
    #include <map>
    #include <unordered_map>
    #include <array>
    #include <functional>

static constexpr char GHOST = 'G';
static constexpr char NIBBLER = 'O';
static constexpr char WALL = 'X';
static constexpr char COIN = '-';
static constexpr char EMPTY = ' ';
static constexpr int ESCAPE = 5;
static constexpr int TIMER_GHOST = 45;
const inline char *GAME_NAME = "Nibbler";

class Nibbler : public IGame {
    public:
        Nibbler();
        ~Nibbler();
        std::vector<std::string> getMap() const override {return map;};
        void setStatus(bool status);
        std::size_t handleNibbler(std::size_t key);
        void setTime();
        std::size_t getScore() const override {return _score;};
        double getTime() const {return _time;};
        void moveNibbler(std::size_t y, std::size_t x);
        void loose_condition(std::vector<std::string> map, std::size_t y, std::size_t x);
        void eat_apple(std::size_t y, std::size_t x);
        void addNibbler_apple(std::size_t y, std::size_t x);
        void restart() override;
        void in_loop(std::size_t key);
        void setClock() {_start = clock();};
        bool getStatus() const override {return _status;};
        void add_apple();
        void runGame(std::size_t key) override;
        std::unordered_map<char, std::array<u_int8_t, 4>> getRgbValues() const override {return _rgbmap;};
    private:
        std::map<std::size_t, std::pair<std::size_t, std::size_t>>  _coord;
        bool _is_loose;
        bool _is_apple;
        double _sink;
        double _time;
        double _time_ghost;
        bool _status;
        clock_t _start;
        std::size_t _score;
        std::unordered_map<char, std::array<u_int8_t, 4>> _rgbmap {
            {WALL, {255, 255, 255, 255}},
            {NIBBLER, {255, 255, 0, 255}},
            {COIN, {255, 0, 255, 255}},
            {EMPTY, {0, 0, 0, 255}}
        };
        std::vector<std::string> map = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XOOOO                      X",
            "X             XXXX         X",
            "X                X         X",
            "X                          X",
            "X     -      X  X      X   X",
            "X            X  X      X   X",
            "X            X  X      X   X",
            "X   XXXX     X  X      X   X",
            "X               X          X",
            "X               X   XX     X",
            "X           XXXXX          X",
            "X             XX           X",
            "X              X       XX  X",
            "X    XX                XX  X",
            "X      X               XX  X",
            "X      X       XXXX        X",
            "X                 X        X",
            "X           X     X        X",
            "X     XX    X              X",
            "X     XX    X              X",
            "X     XX              X    X",
            "X     XX              X    X",
            "X     XX              X    X",
            "X                          X",
            "X         XXXXXXX          X",
            "X                          X",
            "X     XXX           XX     X",
            "X                          X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        };
};

#endif
