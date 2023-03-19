/*
** EPITECH PROJECT, 2023
** ncurse.cpp
** File description:
** ncurse.cpp
*/

#include "ncurse_lib.hpp"

Ncurse::Ncurse()
{
    _window = initscr();
    keypad(stdscr, TRUE);
    start_color();
    _lastKey = 0;
    nodelay(_window, TRUE);
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
}

Ncurse::~Ncurse()
{
    delwin(_window);
    endwin();
    std ::cout << "Ncurse destructor" << std::endl;
}

void Ncurse::displayMap(std::vector<std::string> map)
{
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'X')
                attron(COLOR_PAIR(1));
            else if (map[i][j] == 'O')
                attron(COLOR_PAIR(2));
            else if (map[i][j] == 'G')
                attron(COLOR_PAIR(3));
            if (map[i][j] == 'A' || map[i][j] == 'B')
                mvprintw(i, j, " ", map[i][j]);
            else
                mvprintw(i, j, "%c", map[i][j]);
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
        }
    }
}

int Ncurse::handleEvent()
{
    int ch = getch();

    if (ch == 'q') {
        _lastKey = ESCAPE;
        return (_lastKey);
    }
    if (ch == ' ') {
        _lastKey = SPACE;
    }
    if (ch == KEY_BACKSPACE) {
        _lastKey = ENTER;
        std ::cout << "ENTER" << std::endl;
    }
    if (ch == KEY_LEFT) {
        _lastKey = LEFT;
        std ::cout << "ENTER" << std::endl;
        return (_lastKey);
    }
    if (ch == KEY_RIGHT) {
        _lastKey = RIGHT;
        return (_lastKey);
    }
    if (ch == KEY_UP) {
        _lastKey = UP;
        return (_lastKey);
    }
    if (ch == KEY_DOWN) {
        _lastKey = DOWN;
        return (_lastKey);
    }
    return (_lastKey);
}

extern "C" {
    ILib *entryLib() {
        return new Ncurse();
    }
}
