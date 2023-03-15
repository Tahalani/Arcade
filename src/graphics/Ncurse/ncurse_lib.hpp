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

class Ncurse : public ILib {
    public:
        Ncurse() {};
        ~Ncurse() {};
        void init() {};
        void stop() {};
    protected:
    private:
};

#endif