/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** FalseComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public AComponent {
        public:
            FalseComponent()
            {
                std::vector<nts::node> list(1);
                pins = list;
            };
            ~FalseComponent() = default;
            nts::Tristate compute(std::size_t pin)
            {
                if (pin != 1)
                    throw std::invalid_argument("Pin doesn't exist");
                return False;
            };
            void reset(std::size_t pin)
            {
                if (pin != 1)
                    throw std::invalid_argument("Pin doesn't exist");
                visited = false;
            };

        protected:
        private:
    };
}
