/*
** EPITECH PROJECT, 2023
** loader.hpp
** File description:
** loader.hpp
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

#include <string>
#include <iostream>
#include <memory>

template <typename T>
class Loader {
    public:
        class ErrorParser : public std::exception{
            public:
                ErrorParser(std::string message) : _message(message) {}
                ~ErrorParser() {};
                const char *what() const noexcept { return _message.c_str(); };
            private:
                std::string _message;
        };
        Loader() {
            _lib = nullptr;
        }
        ~Loader() {
            if (_lib)
                delete _lib;
            for (auto &handle : _handles)
                dlclose(handle);
        }
        void LoadLib(std::string &libname, std::string const &point) {
            if (_lib)
                delete _lib;
            T* (*entryLib)();
            std::string entry = "entry" + point;

            void *handle = dlopen(libname.c_str(), RTLD_LAZY);
            if (handle) {
                entryLib = (T* (*)())dlsym(handle, entry.c_str());
                if (entryLib) {
                    _lib = entryLib();
                    _handles.push_back(handle);
                } else {
                    std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
                    throw ErrorParser("NOT A LIB .SO" + libname);
                }
            } else {
                std::cerr << "[LOAD] Error: failed to load " << libname << std::endl;
                throw ErrorParser("[LOAD] Error: failed to load " + libname);
            }
        }
        T *getLib() {
            return _lib;
        }

    private:
        T *_lib;
        std::vector<void *> _handles;
};

#endif /* !LOADER_HPP_ */