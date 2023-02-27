/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** SumComponent
*/

#include "SumComponent.hpp"

nts::SumComponent::SumComponent()
{
    std::vector <nts::node> list(5);
    pins = list;
}

nts::SumComponent::~SumComponent()
{
}

nts::Tristate nts::SumComponent::compute(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 3) {
        return pins[pin - 1].component->compute(pins[pin - 1].other_pin);
    }
    Tristate val1 = pins[0].component->compute(pins[0].other_pin);
    Tristate val2 = pins[1].component->compute(pins[1].other_pin);
    Tristate val3 = pins[2].component->compute(pins[2].other_pin);
    if (pin == 4) {
        if ((val1 == True && val2 == True) || (val1 == True && val3 == True) || (val2 == True && val3 == True)) {
            return True;
        } else if (val1 == Undefined || val2 == Undefined || val3 == Undefined) {
            return Undefined;
        } else {
            return False;
        }
    } else {
        if (val1 == True && val2 == True && val3 == True) {
            return True;
        } else if (val1 == True && val2 == True && val3 == False) {
            return False;
        } else if (val1 == True && val2 == False && val3 == True) {
            return False;
        } else if (val1 == True && val2 == False && val3 == False) {
            return True;
        } else if (val1 == False && val2 == True && val3 == True) {
            return False;
        } else if (val1 == False && val2 == True && val3 == False) {
            return True;
        } else if (val1 == False && val2 == False && val3 == True) {
            return True;
        } else if (val1 == False && val2 == False && val3 == False) {
            return False;
        } else {
            return Undefined;
        }
    }
}
