/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts
{
    class AndComponent : public nts::AComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate compute(std::size_t pin);
            void reset(std::size_t pin);
        protected:
        private:
    };
}
#endif /* !ANDCOMPONENT_HPP_ */
