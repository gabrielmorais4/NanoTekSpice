/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent()
{
    std::vector<nts::node> list(1);
    pins = list;
    value = Undefined;
}

nts::InputComponent::~InputComponent()
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::invalid_argument("Pin doesn't exist");
    return value;
}

nts::Tristate nts::InputComponent::getValue() const
{
    return value;
}

void nts::InputComponent::setValue(nts::Tristate new_value)
{
    value = new_value;
}
