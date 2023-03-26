/*
** EPITECH PROJECT, 2023
** Snake.hpp
** File description:
** Snake.hpp
*/

#ifndef SNAKE_HPP
    #define SNAKE_HPP
    #include "../IGame.hpp"
    #include <iostream>
    #include <fstream>
    #include <chrono>
    #include <thread>
    #include <unordered_map>
    #include <array>
    #include <sstream>
    #include <ctime>
    #include <cstdlib>
    #include <cmath>

static constexpr char GHOST = 'G';
static constexpr char PACMAN = 'O';
static constexpr char WALL = 'X';
static constexpr char COIN = '-';
static constexpr char BOOST = 'W';
static constexpr char EMPTY = ' ';
// static constexpr int LEFT = 1;
// static constexpr int RIGHT = 2;
// static constexpr int UP = 3;
// static constexpr int DOWN = 4;
static constexpr int ESCAPE = 5;
static constexpr int TIMER_GHOST = 45;
const inline char *GAME_NAME = "Pacman";

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();
        std::vector<std::string> getMap() const override {return map;};
        std::size_t moveSnake(std::size_t direction, std::vector<std::string> &map);
        std::size_t getScore() const override {return _score;};
        std::size_t getGoal() const {return _goal;};
        void setPos_tp(std::vector<std::string> map);
        void setClock() {_start = clock();};
        void setLevel() {_level += 1;};
        double getTime() const {return _time;};
        bool is_loose() const;
        void setTimeGoal();
        bool is_win() const;
        void set_time_ghost();
        bool getStatus() const override {return _status;};
        void setStatus(bool status);
        void loose_condition(std::vector<std::string> map);
        void setnumberGhost(std::vector<std::string> map);
        void runGame(std::size_t key) override;
        void moveGhost(std::vector<std::string> &map);
        void setGoal(std::vector<std::string> map);
        void in_loop(std::size_t key, std::vector<std::string> &map_tmp);
        void setTime();
        void setMapSize(std::vector<std::string> map);
        void setIsBoost(bool is_boost) {_is_boost = is_boost;};
        void restart() override;
        std::unordered_map<char, std::array<u_int8_t, 4>> getRgbValues() const override {return _rgbmap;};
    private:
    protected:
        std::size_t _key;
        bool _is_loose;
        double _sink;
        double _time;
        bool _is_boost;
        double _time_ghost;
        bool _status;
        float _time_goal;
        std::size_t _level;
        std::size_t _map_size_x;
        std::size_t _map_size_y;
        clock_t _start;
        std::size_t _nbrGhost;
        std::size_t _score;
        std::size_t _goal;
        std::size_t _pos_tp_A_x;
        std::size_t _pos_tp_A_y;
        std::size_t _pos_tp_B_x;
        std::size_t _pos_tp_B_y;
        std::vector<std::string> _map_history;
        std::unordered_map<char, std::array<u_int8_t, 4>> _rgbmap {
            {EMPTY, {0, 0, 0, 255}},
            {WALL, {255, 255, 255, 255}},
            {COIN, {255, 0, 255, 255}},
            {PACMAN, {255, 255, 0, 255}},
            {GHOST, {255, 0, 0, 255}},
            {BOOST, {0, 255, 255, 255}},
        };
        std::vector<std::string> map = {
            "                            ",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XW-----------XX-----------WX",
            "X-XXXX-XXXXX-XX-XXXXX-XXXX-X",
            "X-XXXX-XXXXX-XX-XXXXX-XXXX-X",
            "X--------------------------X",
            "X-XXXX-XX-XXXXXXXX-XX-XXXX-X",
            "X-XXXX-XX-XXXXXXXX-XX-XXXX-X",
            "X------XX----XX----XX------X",
            "XXXXXX-XXXXX-XX-XXXXX-XXXXXX",
            "     X-XXXXX XX XXXXX-X     ",
            "     X-XX          XX-X     ",
            "     X-XX X XXXX X XX-X     ",
            "XXXXXX-XX XGX  XGX XX-XXXXXX",
            "A     -   XXX  XXX   -     B",
            "XXXXXX-XX XGX  XGX XX-XXXXXX",
            "     X-XX X XXXX X XX-X     ",
            "     X-XX     O    XX-X     ",
            "     X-XX XXXXXXXX XX-X     ",
            "XXXXXX-XX XXXXXXXX XX-XXXXXX",
            "X------------XX------------X",
            "X-XXXX-XXXXX-XX-XXXXX-XXXX-X",
            "X-XXXX-XXXXX-XX-XXXXX-XXXX-X",
            "X---XX----------------XX---X",
            "XXX-XX-XX-XXXXXXXX-XX-XX-XXX",
            "XXX-XX-XX-XXXXXXXX-XX-XX-XXX",
            "X------XX----XX----XX------X",
            "X-XXXXXXXXXX-XX-XXXXXXXXXX-X",
            "X-XXXXXXXXXX-XX-XXXXXXXXXX-X",
            "XW------------------------WX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        };
};

#endif
