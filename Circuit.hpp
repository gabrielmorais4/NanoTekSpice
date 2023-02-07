/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Circuit
*/

#pragma once

#include <map>
#include "IComponent.hpp"
#include "InputComponent.hpp"
#include <iostream>
#include <memory>

class Circuit {
    public:
        Circuit();
        ~Circuit();
        void addComp(const std::string &name, nts::IComponent &comp);
        nts::IComponent &getComp(const std::string &name) const;
        std::map<std::string, std::unique_ptr<nts::IComponent>> getMap() {return map;};
        void display();

    protected:
        size_t tick = 0;
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
    private:
};
