/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** OrComponent
*/

#include "OrComponent.hpp"

nts::OrComponent::OrComponent()
{
    std::vector<nts::node> list(3);
    pins = list;
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 1 || pin == 2) {
        return pins[pin - 1].component->compute(pins[pin - 1].other_pin);
    }

    int val1 = pins[0].component->compute(pins[0].other_pin);
    int val2 = pins[1].component->compute(pins[1].other_pin);
    if (val1 == True || val2 == True) {
        return True;
    }
    if (val1 == Undefined || val2 == Undefined) {
        return Undefined;
    }
    return False;
}
