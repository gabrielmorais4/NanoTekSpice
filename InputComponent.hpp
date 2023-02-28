/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public nts::AComponent {
        public:
            InputComponent();
            ~InputComponent();
            nts::Tristate compute(std::size_t pin);
            void setValue(nts::Tristate value);
            nts::Tristate getValue() const;
            void reset(std::size_t pin);
        protected:
        private:
            nts::Tristate value;
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
