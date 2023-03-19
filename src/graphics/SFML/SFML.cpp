/*
** EPITECH PROJECT, 2023
** sfml.cpp
** File description:
** sfml.cpp
*/

#include "sfml_lib.hpp"

SFML::SFML()
{
    _window.create(sf::VideoMode(WIDTH, HEIGHT, 32), GAME_NAME, sf::Style::Default);
    _lastKey = 0;
}

SFML::~SFML()
{
    _window.close();
}

void SFML::displayMap(std::vector<std::string> map)
{
    int position_x = 0;
    int position_y = 0;
    Vector2i pos = {position_x, position_y};
    Vector2i size = {28, 28};
    rgba color = {255, 0, 0, 255};

    pos.x = HEIGHT / 2;
    pos.y = 100;
    drawText("PACMAN", {800, 0}, 100);
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == WALL) {
                color = {255, 255, 255, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == EMPTY) {
                color = {0, 0, 0, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == COIN) {
                color = {255, 0, 255, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == PACMAN) {
                color = {255, 255, 0, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == GHOST) {
                color = {255, 0, 0, 255};
                drawRect(pos, size, color);
            }
            pos.x += 28;
        }
        pos.x = HEIGHT / 2;
        pos.y += 28;
    }
    _window.display();
    _window.clear(sf::Color::Black);
}

void SFML::drawText(const std::string text, const Vector2i pos, const size_t size)
{
    sf::Font font;
    sf::Text textToDisplay;
    if (!font.loadFromFile("ressources/font.ttf"))
        return;
    textToDisplay.setFont(font);
    textToDisplay.setString(text);
    textToDisplay.setCharacterSize(size);
    textToDisplay.setFillColor(sf::Color::White);
    textToDisplay.setPosition(pos.x, pos.y);
    _window.draw(textToDisplay);
}

void SFML::drawRect(const Vector2i pos, const Vector2i size, const rgba color)
{
    sf::RectangleShape rect(sf::Vector2f(size.x, size.y));
    rect.setPosition(pos.x, pos.y);
    rect.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    _window.draw(rect);
}

int SFML::handleEvent()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _lastKey = ESCAPE;
            return _lastKey;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down && _lastKey !=  sf::Keyboard::Up) {
                _lastKey = DOWN;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Up && _lastKey != sf::Keyboard::Down) {
                _lastKey = UP;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Left && _lastKey != sf::Keyboard::Right) {
                _lastKey = LEFT;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Right && _lastKey != sf::Keyboard::Left) {
                _lastKey = RIGHT;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Escape) {
                _lastKey = ESCAPE;
                return _lastKey;
            }
        }
    }
    return _lastKey;
}

extern "C" {
    ILib *entryLib() {
        return new SFML();
    }
}
