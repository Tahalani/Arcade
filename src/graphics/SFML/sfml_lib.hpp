/*
** EPITECH PROJECT, 2023
** sfml.hpp
** File description:
** sfml.hpp
*/

#ifndef SFML_LIB_HPP
    #define SFML_LIB_HPP

    #include "../ILib.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

#define WIDTH 1920
#define HEIGHT 1080
#define GAME_NAME "Arcade"

class SFML : public ILib{
    public:
        SFML();
        ~SFML();
        int handleEvent() override;
        void drawText(const std::string text, const Vector2i pos, const size_t size) override;
        void drawRect(const Vector2i pos, const Vector2i size, const rgba color) override;
        void displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbg) override;
        void menu() override;
    private:
        sf::RenderWindow _window;
        int _lastKey;
};

#endif
