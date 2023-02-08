/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Circuit
*/

#pragma once

#include "IComponent.hpp"
#include "OutputComponent.hpp"
#include "InputComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include <map>
#include <iostream>
#include <memory>

class Circuit {
    public:
        Circuit();
        ~Circuit();
        void Circuit::addComp(const std::string &name, const nts::IComponent *component);
        nts::IComponent *Circuit::getComp(const std::string &name) const;
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getMap();
        void display();

    protected:
        size_t tick = 0;
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
    private:
};
