/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
{
    setValue(Undefined);
}

nts::ClockComponent::~ClockComponent()
{
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::invalid_argument("Pin doesn't exist");
    return getValue();
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    //change this later
    (void)tick;
    if (getValue() == Undefined)
        setValue(Undefined);
    else if (getValue() == False)
        setValue(True);
    else if (getValue() == True)
        setValue(False);
}
