/*
** EPITECH PROJECT, 2023
** Nibbler.cpp
** File description:
** Nibbler.cpp
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    _status = true;
    _time = 0;
    _is_apple = false;
    _coord.insert({0, std::pair<std::size_t, std::size_t>(1, 4)});
    _coord.insert({1, std::pair<std::size_t, std::size_t>(1, 3)});
    _coord.insert({2, std::pair<std::size_t, std::size_t>(1, 2)});
    _coord.insert({3, std::pair<std::size_t, std::size_t>(1, 1)});
    setClock();
}

Nibbler::~Nibbler()
{
}

void Nibbler::runGame(std::size_t key)
{
    setTime();
    double time = getTime();
    if (time > 0.2) {
        in_loop(key);
        if (_is_loose == true)
            restart();
        setClock();
    }
}

void Nibbler::in_loop(std::size_t key)
{
    if (key == QUIT)
        setStatus(false);
    if (key == LEFT || key == RIGHT || key == UP || key == DOWN) {
        handleNibbler(key);
    }
}

void Nibbler::restart()
{
    _coord.clear();
    _coord.insert({0, std::pair<std::size_t, std::size_t>(1, 4)});
    _coord.insert({1, std::pair<std::size_t, std::size_t>(1, 3)});
    _coord.insert({2, std::pair<std::size_t, std::size_t>(1, 2)});
    _coord.insert({3, std::pair<std::size_t, std::size_t>(1, 1)});
    _is_loose = false;
    _status = true;
    _time = 0;
    map = {
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
}

void Nibbler::loose_condition(std::vector<std::string> map, std::size_t y, std::size_t x)
{
    if (map[y][x] == WALL || map[y][x] == NIBBLER)
        _is_loose = true;
}

void Nibbler::setStatus(bool status)
{
    _status = status;
}

void Nibbler::eat_apple(std::size_t y, std::size_t x)
{
    if (map[y][x] == COIN)
        _is_apple = true;
}

void Nibbler::add_apple()
{
    std::size_t y = 0;
    std::size_t x = 0;
    while (1) {
        y = rand() % map.size();
        x = rand() % map[0].length();
        if (map[y][x] == EMPTY)
            break;
    }
    map[y][x] = COIN;
}

void Nibbler::addNibbler_apple(std::size_t y, std::size_t x)
{
    if (_is_apple == true) {
        _coord.insert({_coord.size(), {y, x}});
        map[y][x] = NIBBLER;
        _is_apple = false;
        add_apple();
    }
}

void Nibbler::moveNibbler(std::size_t y, std::size_t x)
{
    std::pair<std::size_t, std::size_t> oldCase;
    std::pair<std::size_t, std::size_t> newCase;

    oldCase.first = _coord.begin()->second.first;
    oldCase.second = _coord.begin()->second.second;

    for (auto it = _coord.begin(); it != _coord.end(); ++it) {
        if (it == _coord.begin()) {
            loose_condition(map, it->second.first + y, it->second.second + x);
            eat_apple(it->second.first + y, it->second.second + x);
            map[it->second.first + y][it->second.second + x] = NIBBLER;
            map[it->second.first][it->second.second] = EMPTY;
            _coord[it->first] = {it->second.first + y, it->second.second + x};
        } else {
            map[oldCase.first][oldCase.second] = NIBBLER;
            map[it->second.first][it->second.second] = EMPTY;
            newCase = {it->second.first, it->second.second};
            _coord[it->first] = {oldCase.first, oldCase.second};
            oldCase = {newCase.first, newCase.second};
        }
    }
    addNibbler_apple(oldCase.first, oldCase.second);
}

std::size_t Nibbler::handleNibbler(std::size_t key)
{
    const std::map<std::size_t, std::function<void
    (std::size_t, std::size_t)>> ptr_fct = {
        {LEFT, std::bind(&Nibbler::moveNibbler, this, 0, -1)},
        {RIGHT, std::bind(&Nibbler::moveNibbler, this, 0, 1)},
        {UP, std::bind(&Nibbler::moveNibbler, this, -1, 0)},
        {DOWN, std::bind(&Nibbler::moveNibbler, this, 1, 0)}
    };

    ptr_fct.at(key)(0, 0);
    return (0);
}

void Nibbler::setTime()
{
    for (size_t i = 0; i < 3141592; ++i)
        _sink += sin(i);
    clock_t end = clock();
    _time = ((double) (end - _start)) / CLOCKS_PER_SEC;
}

extern "C" {
    IGame *entryGame() {
        return new Nibbler();
    }
}
