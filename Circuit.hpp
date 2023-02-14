/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Circuit
*/

#pragma once

#include "AComponent.hpp"
#include "OutputComponent.hpp"
#include "InputComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "ClockComponent.hpp"
#include <map>
#include <iostream>
#include <memory>

class Circuit : public nts::AComponent {
    public:
        Circuit(size_t pins = 0);
        ~Circuit();
        void addComp(const std::string &name, std::unique_ptr<nts::IComponent> component);
        nts::IComponent *getComp(const std::string &name) const;
        std::map<std::string, std::unique_ptr<nts::IComponent>> *getMap() {return &map;};
        size_t getTick() const { return tick; };
        void setTick(size_t new_tick) { tick = new_tick; };
        nts::Tristate compute(std::size_t pin);

    protected:
        size_t tick = 0;
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
    private:
};
