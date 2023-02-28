/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** OrComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class OrComponent : public nts::AComponent {
        public:
            OrComponent();
            ~OrComponent() = default;
            nts::Tristate compute(std::size_t pin);
            void reset(std::size_t pin);

        protected:
        private:
    };
}
