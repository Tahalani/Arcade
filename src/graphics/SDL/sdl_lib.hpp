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

class SDL : public ILib {
    public:
        SDL() {};
        ~SDL() {};
        void init() override {};
        void stop() override {};
    protected:
    private:
};

#endif