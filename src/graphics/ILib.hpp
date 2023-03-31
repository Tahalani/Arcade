/*
** EPITECH PROJECT, 2023
** Ilib.hpp
** File description:
** Ilib.hpp
*/

#ifndef ILIB_HPP_
    #define ILIB_HPP_

    #include <array>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_map>

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
        VALID,
        RESET
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
