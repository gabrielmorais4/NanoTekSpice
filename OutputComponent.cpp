/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent()
{
    std::vector<nts::node> list(1);
    pins = list;
    value = Undefined;
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::invalid_argument("Pin doesn't exist");
    if (pins[0].component == nullptr)
        return Undefined;
    return pins[0].component->compute(pins[0].other_pin);
}
