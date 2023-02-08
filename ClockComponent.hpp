/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** ClockComponent
*/

#pragma once

#include "InputComponent.hpp"

namespace nts {
    class ClockComponent : public nts::InputComponent {
        public:
            ClockComponent();
            ~ClockComponent();
            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}
