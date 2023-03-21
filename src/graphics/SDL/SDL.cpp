/*
** EPITECH PROJECT, 2023
** sdl.cpp
** File description:
** sdl.cpp
*/

#include "sdl_lib.hpp"

SDL::SDL()
{
    _lastKey = 0;
    _window = SDL_CreateWindow (GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _surface = SDL_GetWindowSurface(_window);
    SDL_UpdateWindowSurface(_window);
}

SDL::~SDL()
{
    SDL_DestroyWindow(_window);
}

void SDL::menu()
{
    SDL_UpdateWindowSurface(_window);
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

void SDL::drawText(const std::string text, const Vector2i pos, const size_t size)
{
    (void)text;
    (void)pos;
    (void)size;
}

void SDL::drawRect(const Vector2i pos, const Vector2i size, const rgba color)
{
    SDL_Rect rect;

    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size.x;
    rect.h = size.y;
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
    SDL_RenderDrawRect(_renderer, &rect);
}

void SDL::displayMap(std::vector<std::string> map)
{
    int position_x = 0;
    int position_y = 0;
    Vector2i pos = {position_x, position_y};
    Vector2i size = {28, 28};
    rgba color = {255, 0, 0, 255};

    pos.x = HEIGHT / 2;
    pos.y = 100;
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == WALL) {
                color = {0, 0, 0, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == EMPTY || map[i][j] == 'A' || map[i][j] == 'B') {
                color = {255, 255, 255, 255};
                drawRect(pos, size, color);
            }
            if (map[i][j] == COIN) {
                color = {100, 235, 100, 255};
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
    SDL_RenderPresent(_renderer);
}

int SDL::handleEvent()
{
    SDL_Event _event;

    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _lastKey = ESCAPE;
            return (_lastKey);
        }
        if (_event.type == SDL_KEYDOWN) {
            if (_event.key.keysym.sym == SDLK_ESCAPE) {
                _lastKey = ESCAPE;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_SPACE) {
                _lastKey = SPACE;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_RETURN) {
                _lastKey = ENTER;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_LEFT) {
                _lastKey = LEFT;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_RIGHT) {
                _lastKey = RIGHT;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_UP) {
                _lastKey = UP;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_DOWN) {
                _lastKey = DOWN;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_p) {
                _lastKey = P;
                return (_lastKey);
            }
        }
    }
    if ((_lastKey != SPACE && _lastKey != ENTER))
        return _lastKey;
    return (0);
}

extern "C" {
    ILib *entryLib() {
        return new SDL();
    }
}
