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

void Circuit::addComp(const std::string &name, const nts::IComponent *component)
{
    map[name] = std::make_unique<nts::IComponent>(component);
}

nts::IComponent *Circuit::getComp(const std::string &name) const
{
    return map.at(name).get();
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getMap()
{
    return map;
}

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = map.begin(); it != map.end(); it++){
        nts::InputComponent *component = dynamic_cast<nts::InputComponent *>(it->second.get());
        if (component) {
            std::cout << it->first << ": " << component->compute(1) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = map.begin(); it != map.end(); it++){
        nts::OutputComponent *component = dynamic_cast<nts::OutputComponent *>(it->second.get());
        if (component) {
            std::cout << it->first << ": " << component->compute(1) << std::endl;
        }
    }
}
