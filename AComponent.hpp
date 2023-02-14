/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include <vector>

namespace nts
{
    struct node {
        nts::IComponent *component;
        size_t other_pin;
    };

    class AComponent : public nts::IComponent {
        public:
            AComponent(){};
            ~AComponent(){};
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void simulate(std::size_t tick)
            {
                (void)tick;
            };
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void setUnidirectionalLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::IComponent *getPinConnexion(std::size_t index);


        protected:
            std::vector<nts::node> pins;
        private:
    };
}
