/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::addComp(const std::string &name, nts::IComponent *component)
{
    map[name].reset(component);
}


nts::IComponent *Circuit::getComp(const std::string &name) const
{
    return map.at(name).get();
}


