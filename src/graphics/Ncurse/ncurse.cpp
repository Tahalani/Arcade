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

void Ncurse::menu()
{
    refresh();
}

void Ncurse::drawText(const std::string text, const Vector2i pos, const size_t size)
{
    (void)size;
    mvprintw(pos.y / 50, pos.x / 50, text.c_str());
}

void Ncurse::displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbg)
{
    (void)rbg;
    mvprintw(30, 10, "Score: %d", score);
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
        _lastKey = QUIT;
        return (_lastKey);
    }
    if (ch == ' ') {
        _lastKey = GAME;
        return (_lastKey);
    }
    if (ch == KEY_BACKSPACE) {
        _lastKey = LIB;
        return (_lastKey);
    }
    if (ch == KEY_LEFT) {
        _lastKey = LEFT;
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
    if (ch == 'p') {
        _lastKey = VALID;
        return (_lastKey);
    }
    if (ch == 'a') {
        return 'A';
    }
    if (ch == 'b') {
        return 'B';
    }
    if (ch == 'c') {
        return 'C';
    }
    if (ch == 'd') {
        return 'D';
    }
    if (ch == 'e') {
        return 'E';
    }
    if (ch == 'f') {
        return 'F';
    }
    if (ch == 'g') {
        return 'G';
    }
    if (ch == 'h') {
        return 'H';
    }
    if (ch == 'i') {
        return 'I';
    }
    if (ch == 'j') {
        return 'J';
    }
    if (ch == 'k') {
        return 'K';
    }
    if (ch == 'l') {
        return 'L';
    }
    if (ch == 'm') {
        return 'M';
    }
    if (ch == 'n') {
        return 'N';
    }
    if (ch == 'o') {
        return 'O';
    }
    if (ch == 'r') {
        return 'R';
    }
    if (ch == 's') {
        return 'S';
    }
    if (ch == 't') {
        return 'T';
    }
    if (ch == 'u') {
        return 'U';
    }
    if (ch == 'v') {
        return 'V';
    }
    if (ch == 'w') {
        return 'W';
    }
    if (ch == 'x') {
        return 'X';
    }
    if (ch == 'y') {
        return 'Y';
    }
    if (ch == 'z') {
        return 'Z';
    }
    if ((_lastKey != GAME && _lastKey != LIB))
        return _lastKey;
    return (0);
}

extern "C" {
    ILib *entryLib() {
        return new Ncurse();
    }
}
