/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais [WSL : Debian]
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
#define LOGGERCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
    class LoggerComponent : public nts::AComponent {
    public:
        LoggerComponent();
        ~LoggerComponent() = default;
        nts::Tristate compute(std::size_t pin);
        void reset(std::size_t pin);
        void simulate(std::size_t tick);
    protected:
    private:
};
}


#endif /* !LOGGERCOMPONENT_HPP_ */
