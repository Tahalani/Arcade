/*
** EPITECH PROJECT, 2023
** Snake.cpp
** File description:
** Snake.cpp
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    _is_loose = false;
    _score = 0;
    _status = true;
    _time_ghost = 0;
    _map_history = getMap();
    setClock();
    setPos_tp(getMap());
    setGoal(getMap());
    setnumberGhost(getMap());
}

Pacman::~Pacman()
{
}

void Pacman::restart()
{
    _time_ghost = 0;
    _is_loose = false;
    _score = 0;
    map = {
        "                            ",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X------------XX------------X",
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
        "X--------------------------X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };
    setGoal(map);
    setnumberGhost(map);
}

void Pacman::in_loop(std::size_t key, std::vector<std::string> &map)
{
    if (key == QUIT) {
        setStatus(false);
    }
    if (key == LEFT || key == RIGHT || key == UP || key == DOWN) {
        set_time_ghost();
        moveSnake(key, map);
        moveGhost(map);
        loose_condition(map);
    }
}

void Pacman::runGame(std::size_t key)
{
    setTime();
    double time = getTime();
    if (time > 0.2) {
        in_loop(key, map);
        if (is_loose())
            restart();
        if (is_win()) {
            std::cout << "You win" << std::endl;
            restart();
        }
        setClock();
    }
}

void Pacman::setStatus(bool status)
{
    _status = status;
}

std::size_t Pacman::moveSnake(std::size_t key, std::vector<std::string> &map)
{
    if (key == LEFT) {
        for (std::size_t i = 0; i < map.size(); i++) {
            for (std::size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == PACMAN && map[i][j - 1] != WALL) {
                    if (map[i][j - 1] == COIN)
                        _score++;
                    if (map[i][j - 1] == 'A') {
                        map[_pos_tp_B_x][_pos_tp_B_y - 1] = PACMAN;
                        map[i][j] = EMPTY;
                        return (1);
                    }
                    _map_history[i][j] = 'I';
                    map[i][j - 1] = PACMAN;
                    map[i][j] = EMPTY;
                    return (1);
                }
            }
        }
    }
    if (key == RIGHT) {
        for (std::size_t i = 0; i < map.size(); i++) {
            for (std::size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == PACMAN && map[i][j + 1] != WALL) {
                    if (map[i][j + 1] == COIN)
                        _score++;
                    if (map[i][j + 1] == 'B') {
                        map[_pos_tp_A_x][_pos_tp_A_y + 1] = PACMAN;
                        map[i][j] = EMPTY;
                        return (1);
                    }
                    _map_history[i][j] = 'I';
                    map[i][j + 1] = PACMAN;
                    map[i][j] = EMPTY;
                    return (1);
                }
            }
        }
    }
    if (key == UP) {
        for (std::size_t i = 0; i < map.size(); i++) {
            for (std::size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == PACMAN && map[i - 1][j] != WALL) {
                    if (map[i - 1][j] == COIN)
                        _score++;
                    _map_history[i][j] = 'I';
                    map[i - 1][j] = PACMAN;
                    map[i][j] = EMPTY;
                    return (1);
                }
            }
        }
    }
    if (key == DOWN) {
        for (std::size_t i = 0; i < map.size(); i++) {
            for (std::size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == PACMAN && map[i + 1][j] != WALL) {
                    if (map[i + 1][j] == COIN)
                        _score++;
                    _map_history[i][j] = 'I';
                    map[i + 1][j] = PACMAN;
                    map[i][j] = EMPTY;
                    return (1);
                }
            }
        }
    }
    return (0);
}

void Pacman::setPos_tp(std::vector<std::string> map)
{
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'A') {
                _pos_tp_A_x = i;
                _pos_tp_A_y = j;
            }
            if (map[i][j] == 'B') {
                _pos_tp_B_x = i;
                _pos_tp_B_y = j;
            }
        }
    }
}

void Pacman::setGoal(std::vector<std::string> map)
{
    std::size_t goal = 0;

    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == COIN)
                goal++;
        }
    }
    _goal = goal;
}

void Pacman::setnumberGhost(std::vector<std::string> map)
{
    std::size_t ghosts = 0;

    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == GHOST)
                ghosts++;
        }
    }
    _nbrGhost = ghosts;
}

bool Pacman::is_win() const
{
    if (_score == _goal)
        return true;
    return false;
}

void Pacman::moveGhost(std::vector<std::string> &map)
{
    int num = 0;

    srand(time(NULL));
    if (_time_ghost > TIMER_GHOST) {
        for (std::size_t i = 0; i < map.size(); i++) {
            for (std::size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == GHOST) {
                    num = rand() % 4;
                    if (num == 0 && map[i + 1][j] != WALL && map[i + 1][j] != GHOST && map[i + 1][j] != 'B' && map[i + 1][j] != 'A') {
                        if (_map_history[i][j] == 'I' || _map_history[i][j] == EMPTY || _map_history[i][j] == GHOST)
                            map[i][j] = EMPTY;
                        else
                            map[i][j] = COIN;
                        map[i + 1][j] = GHOST;
                    }
                    if (num == 1 && map[i - 1][j] != WALL && map[i - 1][j] != GHOST && map[i - 1][j] != 'B' && map[i - 1][j] != 'A') {
                        if (_map_history[i][j] == 'I' || _map_history[i][j] == EMPTY || _map_history[i][j] == GHOST)
                            map[i][j] = EMPTY;
                        else
                            map[i][j] = COIN;
                        map[i - 1][j] = GHOST;
                    }
                    if (num == 2 && map[i][j + 1] != WALL && map[i][j + 1] != GHOST && map[i][j + 1] != 'B' && map[i][j + 1] != 'A') {
                        if (_map_history[i][j] == 'I' || _map_history[i][j] == EMPTY || _map_history[i][j] == GHOST)
                            map[i][j] = EMPTY;
                        else
                            map[i][j] = COIN;
                        map[i][j + 1] = GHOST;
                    }
                    if (num == 3 && map[i][j - 1] != WALL && map[i][j - 1] != GHOST && map[i][j - 1] != 'B' && map[i][j - 1] != 'A') {
                        if (_map_history[i][j] == 'I' || _map_history[i][j] == EMPTY || _map_history[i][j] == GHOST)
                            map[i][j] = EMPTY;
                        else
                            map[i][j] = COIN;
                        map[i][j - 1] = GHOST;
                    }
                }
            }
        }
    }
}

void Pacman::loose_condition(std::vector<std::string> map)
{
    std::size_t ghosts = 0;
    std::size_t pacman = 0;

    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == GHOST)
                ghosts++;
            if (map[i][j] == PACMAN)
                pacman++;
        }
    }
    if (_nbrGhost != ghosts || pacman != 1)
        _is_loose = true;
}

bool Pacman::is_loose() const
{
    if (_is_loose == true)
        return true;
    return false;
}

void Pacman::setTime()
{
    for (size_t i = 0; i < 3141592; ++i)
        _sink += sin(i);
    clock_t end = clock();
    _time = ((double) (end - _start)) / CLOCKS_PER_SEC;
}

void Pacman::set_time_ghost()
{
    _time_ghost++;
}

extern "C" {
    IGame *entryGame() {
        return new Pacman();
    }
}
