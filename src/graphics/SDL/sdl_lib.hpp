/*
** EPITECH PROJECT, 2023
** sdl.hpp
** File description:
** sdl.hpp
*/

#ifndef SDL_LIB_HPP
    #define SDL_LIB_HPP
    #include "../ILib.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>

#define WIDTH 1920
#define HEIGHT 1080
#define GAME_NAME "Arcade"

class SDL : public ILib{
    public:
        SDL();
        ~SDL();
        int handleEvent() override;
        void drawText(const std::string text, const Vector2i pos, const size_t size) override;
        void drawRect(const Vector2i pos, const Vector2i size, const rgba color) override;
        void displayMap(std::vector<std::string> map, int score, std::unordered_map<char, std::array<u_int8_t, 4>> rbga) override;
        SDL_Window *get_window() {return _window;};
        SDL_Renderer *get_renderer() {return _renderer;};
        void menu() override;
    protected:
        SDL_Window *_window;
        TTF_Font *_font;
        SDL_Renderer *_renderer;
        SDL_Surface *_surface;
        int _lastKey;
    private:
};

#endif
