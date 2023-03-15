/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

#include <string>
#include <iostream>

class Arcade {
    public:
        Arcade(std::string libname);
        ~Arcade();
        std::string getLibName();
    private:
        std::string _libname;

};

#endif /* !ARCADE_HPP_ */
