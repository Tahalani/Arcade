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

void SFML::menu()
{
    _window.display();
    _window.clear(sf::Color::Black);
}

void SFML::displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rgb)
{
    int position_x = 0;
    int position_y = 0;
    Vector2i pos = {position_x, position_y};
    Vector2i size = {28, 28};
    rgba color = {255, 0, 0, 255};

    pos.x = HEIGHT / 2;
    pos.y = 100;
    drawText("Score:", {1400, 200}, 100);
    drawText(std::to_string(score), {1400, 400}, 100);
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            color = {rgb[map[i][j]][0], rgb[map[i][j]][1], rgb[map[i][j]][2], rgb[map[i][j]][3]};
            drawRect(pos, size, color);
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
            _lastKey = QUIT;
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
                _lastKey = QUIT;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Space) {
                _lastKey = GAME;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::Enter) {
                _lastKey = LIB;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::P) {
                _lastKey = VALID;
                return _lastKey;
            }
            if (event.key.code == sf::Keyboard::A) {
                return 'A';
            }
            if (event.key.code == sf::Keyboard::B) {
                return 'B';
            }
            if (event.key.code == sf::Keyboard::C) {
                return 'C';
            }
            if (event.key.code == sf::Keyboard::D) {
                return 'D';
            }
            if (event.key.code == sf::Keyboard::E) {
                return 'E';
            }
            if (event.key.code == sf::Keyboard::F) {
                return 'F';
            }
            if (event.key.code == sf::Keyboard::G) {
                return 'G';
            }
            if (event.key.code == sf::Keyboard::H) {
                return 'H';
            }
            if (event.key.code == sf::Keyboard::I) {
                return 'I';
            }
            if (event.key.code == sf::Keyboard::J) {
                return 'J';
            }
            if (event.key.code == sf::Keyboard::K) {
                return 'K';
            }
            if (event.key.code == sf::Keyboard::L) {
                return 'L';
            }
            if (event.key.code == sf::Keyboard::M) {
                return 'M';
            }
            if (event.key.code == sf::Keyboard::N) {
                return 'N';
            }
            if (event.key.code == sf::Keyboard::O) {
                return 'O';
            }
            if (event.key.code == sf::Keyboard::Q) {
                return 'Q';
            }
            if (event.key.code == sf::Keyboard::R) {
                return 'R';
            }
            if (event.key.code == sf::Keyboard::S) {
                return 'S';
            }
            if (event.key.code == sf::Keyboard::T) {
                return 'T';
            }
            if (event.key.code == sf::Keyboard::U) {
                return 'U';
            }
            if (event.key.code == sf::Keyboard::V) {
                return 'V';
            }
            if (event.key.code == sf::Keyboard::W) {
                return 'W';
            }
            if (event.key.code == sf::Keyboard::X) {
                return 'X';
            }
            if (event.key.code == sf::Keyboard::Y) {
                return 'Y';
            }
            if (event.key.code == sf::Keyboard::Z) {
                return 'Z';
            }
        }
    }
    if ((_lastKey != GAME && _lastKey != LIB))
        return _lastKey;
    return 0;
}

extern "C" {
    ILib *entryLib() {
        return new SFML();
    }
}
