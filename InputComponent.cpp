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

nts :: Tristate nts::InputComponent::compute (std :: size_t pin)
{
    std::cout << pin << std::endl;
    return value;
}
