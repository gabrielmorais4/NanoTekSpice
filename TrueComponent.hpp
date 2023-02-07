/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** TrueComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public nts::AComponent {
        public:
            TrueComponent()
            {
                std::vector<nts::node> list(1);
                pins = list;
            };
            ~TrueComponent() = default;
            nts::Tristate compute(std::size_t pin)
            { 
                if (pin)
                    return True;
            };

        protected:
        private:
    };
}
