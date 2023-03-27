/*
** EPITECH PROJECT, 2023
** ncurse
** File description:
** ncurse
*/

#ifndef NCURSE_LIB_HPP
    #define NCURSE_LIB_HPP
    #include "../ILib.hpp"
    #include <ncurses.h>

#define WIDTH 1920
#define HEIGHT 1080
#define GAME_NAME "Arcade"

class Ncurse : public ILib {
    public:
        Ncurse();
        ~Ncurse();
        int handleEvent() override;
        void drawText(const std::string text, const Vector2i pos, const size_t size) override;
        void drawRect(const Vector2i pos, const Vector2i size, const rgba color) override {(void)pos;(void)size;(void)color;};
        void displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbg) override;
        void menu() override;
    private:
        SCREEN *_screen;
        int _lastKey;
};

#endif
