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

void Circuit::addComp(const std::string &name, nts::IComponent &comp)
{
    map.insert({name, std::unique_ptr<nts::IComponent>(std::make_unique<nts::IComponent>(comp))});
}

nts::IComponent &Circuit::getComp(const std::string &name) const
{
    //if we have problems check it later
    return *map.at(name);
}

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = map.begin(); it != map.end(); it++){
        nts::InputComponent *_lemon = dynamic_cast<InputComponent *>(fruits[i]);
        if (it->second)
    } // we need to only display firstly the int then input then output 
}
