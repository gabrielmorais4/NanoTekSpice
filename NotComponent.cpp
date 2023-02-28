/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** XorComponent
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent()
{
    std::vector<nts::node> list(2);
    pins = list;
}

void nts::NotComponent::reset(std::size_t pin)
{
    visited = false;
    if (pin == 1) {
        pins[pin - 1].component->reset(pins[pin - 1].other_pin);
    }
    pins[0].component->reset(pins[0].other_pin);
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return pins[pin - 1].component->compute(pins[pin - 1].other_pin);
    }
    int val = pins[0].component->compute(pins[0].other_pin);
    if (val == Undefined) {
        return Undefined;
    } else if (val == True) {
        return False;
    } else {
        return True;
    }
}
