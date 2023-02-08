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

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = map.begin(); it != map.end(); it++){
        nts::InputComponent *component = dynamic_cast<nts::InputComponent *>(it->second.get());
        if (component) {
            if (component->value == nts::Undefined)
                std::cout << it->first << ": " << "U" << std::endl;
            else
                std::cout << it->first << ": " << component->value << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = map.begin(); it != map.end(); it++){
        nts::OutputComponent *component = dynamic_cast<nts::OutputComponent *>(it->second.get());
        if (component) {
            nts::Tristate val = component->compute(1);
            if (val == nts::Undefined)
                std::cout << it->first << ": " << "U" << std::endl;
            else
                std::cout << it->first << ": " << val << std::endl;
        }
    }
}
