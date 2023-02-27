/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** SumComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class SumComponent: public nts::AComponent {
        public:
            SumComponent();
            ~SumComponent();
            nts::Tristate compute(std::size_t pin);

        protected:
        private:
            nts::Tristate value;
    };
}
