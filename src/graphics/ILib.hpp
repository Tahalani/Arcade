/*
** EPITECH PROJECT, 2023
** Ilib.hpp
** File description:
** Ilib.hpp
*/

#ifndef ILIB_HPP_
    #define ILIB_HPP_

class ILib {
    public:
        virtual ~ILib() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
};

#endif /* !ILIB_HPP_ */