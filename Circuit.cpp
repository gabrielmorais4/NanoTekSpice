/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(size_t pins)
{
    std::vector<nts::node> list(pins);
    this->pins = list;
}

Circuit::~Circuit()
{
}

void Circuit::addComp(const std::string &name, std::unique_ptr<nts::IComponent> component)
{
    map[name].swap(component);;
}

nts::IComponent *Circuit::getComp(const std::string &name) const
{
    try {
        auto res = map.at(name).get();
        return res;
    } catch (std::exception &e) {
        exit (84);
    }
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    return pins[pin - 1].component->compute(pins[pin - 1].other_pin);
}
