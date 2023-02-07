/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts
{
class XorComponent : public nts::AComponent {
    public:
        XorComponent();
        ~XorComponent();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};
}
#endif /* !XORCOMPONENT_HPP_ */
