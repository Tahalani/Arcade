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

class SFML : public ILib {
    public:
        SFML() {};
        ~SFML() {};
        void init() {};
        void stop() {};
    protected:
    private:
};

#endif