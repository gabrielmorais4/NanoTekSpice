/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent()
{
    std::vector<nts::node> list(3);
    pins = list;
}

nts::XorComponent::~XorComponent()
{
}

void nts::XorComponent::reset(std::size_t pin)
{
    visited = false;
    if (pin == 1 || pin == 2)
        pins[pin - 1].component->reset(pins[pin - 1].other_pin);
    pins[0].component->reset(pins[0].other_pin);
    pins[1].component->reset(pins[1].other_pin);
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin == 1 || pin == 2)
        return pins[pin - 1].component->compute(pins[pin - 1].other_pin);
    int val1 = pins[0].component->compute(pins[0].other_pin);
    int val2 = pins[1].component->compute(pins[1].other_pin);
    if (val1 == Undefined || val2 == Undefined)
        return Undefined;
    if (val1 == True && val2 == False)
        return True;
    if (val1 == False && val2 == True)
        return True;
    return False;
}
