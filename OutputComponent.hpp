/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** OutputComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class OutputComponent : public nts::AComponent {
        public:
            OutputComponent();
            ~OutputComponent();
            nts :: Tristate compute(std :: size_t pin);
        
        protected:
        private:
    };
}
