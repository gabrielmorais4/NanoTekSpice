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
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std :: size_t pin)
{
    return pins[pin- 1].component->compute(pins[pin - 1].other_pin);
}
