/*
** EPITECH PROJECT, 2023
** error.hpp
** File description:
** error.hpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
    #include <iostream>
    #include <exception>

class Error : public std::exception{
    public:
        Error(std::string message) : _message(message) {}
        ~Error() {};
        const char *what() const noexcept { return _message.c_str(); };

    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
