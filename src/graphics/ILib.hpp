/*
** EPITECH PROJECT, 2023
** Ilib.hpp
** File description:
** Ilib.hpp
*/

#ifndef ILIB_HPP_
    #define ILIB_HPP_

    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_map>

static constexpr char GHOST = 'G';
static constexpr char PACMAN = 'O';
static constexpr char WALL = 'X';
static constexpr char COIN = '-';
static constexpr char EMPTY = ' ';
// static constexpr int LEFT = 1;
// static constexpr int RIGHT = 2;
// static constexpr int UP = 3;
// static constexpr int DOWN = 4;
static constexpr int ESCAPE = 5;
static constexpr int SPACE = 6;
static constexpr int ENTER = 7;
static constexpr int P = 8;
static constexpr int TIMER_GHOST = 45;
const inline char *GAME_NAME = "Pacman";


struct Vector2i {
    int x;
    int y;
};

struct rgba {
    u_int8_t r;
    u_int8_t g;
    u_int8_t b;
    u_int8_t a;
};

#ifndef KEY_HPP_
    #define KEY_HPP_
    enum Key {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        QUIT, // quitte le jeu
        PAUSE, // pause
        LIB, // change de lib
        GAME, // change de jeux
        VALID
    };
#endif /* !KEY_HPP_ */

class ILib {
    public:
        virtual ~ILib() = default;
        virtual int handleEvent() = 0;
        virtual void drawText(const std::string text, const Vector2i pos, const size_t size) = 0;
        virtual void drawRect(const Vector2i pos, const Vector2i size, const rgba color) = 0;
        virtual void displayMap(const std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbg) = 0;
        virtual void menu() = 0;
    protected:
    private:
};

#endif /* !ILIB_HPP_ */
