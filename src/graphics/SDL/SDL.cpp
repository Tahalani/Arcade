/*
** EPITECH PROJECT, 2023
** sdl.cpp
** File description:
** sdl.cpp
*/

#include "sdl_lib.hpp"

SDL::SDL()
{
    _lastKey = 404;
    _window = SDL_CreateWindow (GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _surface = SDL_GetWindowSurface(_window);
    SDL_UpdateWindowSurface(_window);
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
    TTF_Init();
}

SDL::~SDL()
{
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

void SDL::menu()
{
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

void SDL::drawText(const std::string text, const Vector2i pos, const size_t size)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect rect;
    TTF_Font *_font = TTF_OpenFont("assets/font.ttf", size);

    surface = TTF_RenderText_Solid(_font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = text.size() * (size / 2);
    rect.h = size;
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(_font);
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

void SDL::displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbg)
{
    int position_x = 0;
    int position_y = 0;
    Vector2i pos = {position_x, position_y};
    Vector2i size = {28, 28};
    rgba color = {255, 0, 0, 255};

    pos.x = HEIGHT / 2;
    pos.y = 100;
    drawText("Score: ", {1400, 300}, 100);
    drawText(std::to_string(score), {1400, 400}, 100);
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map[i].size(); j++) {
            color = {rbg[map[i][j]][0], rbg[map[i][j]][1], rbg[map[i][j]][2], rbg[map[i][j]][3]};
            drawRect(pos, size, color);
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
            _lastKey = QUIT;
            return (_lastKey);
        }
        if (_event.type == SDL_KEYDOWN) {
            if (_event.key.keysym.sym == SDLK_ESCAPE) {
                _lastKey = QUIT;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_SPACE) {
                _lastKey = GAME;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_RETURN) {
                _lastKey = LIB;
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
                _lastKey = VALID;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_TAB) {
                _lastKey = RESET;
                return (_lastKey);
            }
            if (_event.key.keysym.sym == SDLK_a) {
                return 'A';
            }
            if (_event.key.keysym.sym == SDLK_b) {
                return 'B';
            }
            if (_event.key.keysym.sym == SDLK_c) {
                return 'C';
            }
            if (_event.key.keysym.sym == SDLK_d) {
                return 'D';
            }
            if (_event.key.keysym.sym == SDLK_e) {
                return 'E';
            }
            if (_event.key.keysym.sym == SDLK_f) {
                return 'F';
            }
            if (_event.key.keysym.sym == SDLK_g) {
                return 'G';
            }
            if (_event.key.keysym.sym == SDLK_h) {
                return 'H';
            }
            if (_event.key.keysym.sym == SDLK_i) {
                return 'I';
            }
            if (_event.key.keysym.sym == SDLK_j) {
                return 'J';
            }
            if (_event.key.keysym.sym == SDLK_k) {
                return 'K';
            }
            if (_event.key.keysym.sym == SDLK_l) {
                return 'L';
            }
            if (_event.key.keysym.sym == SDLK_m) {
                return 'M';
            }
            if (_event.key.keysym.sym == SDLK_n) {
                return 'N';
            }
            if (_event.key.keysym.sym == SDLK_o) {
                return 'O';
            }
            if (_event.key.keysym.sym == SDLK_q) {
                return 'Q';
            }
            if (_event.key.keysym.sym == SDLK_r) {
                return 'R';
            }
            if (_event.key.keysym.sym == SDLK_s) {
                return 'S';
            }
            if (_event.key.keysym.sym == SDLK_t) {
                return 'T';
            }
            if (_event.key.keysym.sym == SDLK_u) {
                return 'U';
            }
            if (_event.key.keysym.sym == SDLK_v) {
                return 'V';
            }
            if (_event.key.keysym.sym == SDLK_w) {
                return 'W';
            }
            if (_event.key.keysym.sym == SDLK_x) {
                return 'X';
            }
            if (_event.key.keysym.sym == SDLK_y) {
                return 'Y';
            }
            if (_event.key.keysym.sym == SDLK_z) {
                return 'Z';
            }
        }
    }
    if ((_lastKey != GAME && _lastKey != LIB && _lastKey != RESET))
        return _lastKey;
    return (0);
}

extern "C" {
    ILib *entryLib() {
        return new SDL();
    }
}
