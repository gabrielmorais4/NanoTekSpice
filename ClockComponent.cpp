/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
{
    value = Undefined;
}

nts::ClockComponent::~ClockComponent()
{
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::invalid_argument("Pin doesn't exist");
    if (value == Undefined)
        value = Undefined;
    else if (value == False)
        value = True;
    else if (value == True)
        value = False;
    return value;
}
