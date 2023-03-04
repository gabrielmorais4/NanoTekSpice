/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais [WSL : Debian]
** File description:
** LoggerComponent
*/

#include "LoggerComponent.hpp"

nts::LoggerComponent::LoggerComponent()
{
    std::vector <nts::node> list(10);
    pins = list;
}

void nts::LoggerComponent::reset(std::size_t pin)
{
    if (pin != 1)
        throw std::invalid_argument("Pin doesn't exist");
    return;
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate inhibitVal = pins[9].component->compute(pins[9].other_pin);
    nts::Tristate clockVal = pins[8].component->compute(pins[8].other_pin);
    if (inhibitVal != False || clockVal != True)
        return Undefined;
    char binary = 0;
    for (int i = 0; i <= 8; i++) {
        nts::Tristate state = pins[i].component->compute(1);
        if (state == Undefined)
            return nts::Undefined;
        binary |= (state == True ? 1 : 0) << (i);
    }
    std::ofstream file;
    file.open("./log.bin", std::ios::app);
    file.put(binary);
    file.close();
    return Undefined;
}

void nts::LoggerComponent::simulate(std::size_t tick)
{
    (void)tick;
    this->compute(0);
}