/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** NotComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class NotComponent : public nts::AComponent {
        public:
            NotComponent();
            ~NotComponent() = default;
            nts::Tristate compute(std::size_t pin);
        protected:
        private:
    };
}
