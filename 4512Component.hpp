/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais-a160f62b84dae7294b0c693e9cf7378f80f0a231
** File description:
** 4512
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class Component4512: public nts::AComponent {
        public:
            Component4512();
            ~Component4512();
            nts::Tristate compute(std::size_t pin);
            void reset(std::size_t pin){(void)(pin);};

        protected:
        private:
    };
}
