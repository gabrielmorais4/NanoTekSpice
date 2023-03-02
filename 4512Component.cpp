/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais-a160f62b84dae7294b0c693e9cf7378f80f0a231
** File description:
** 4512
*/

#include "4512Component.hpp"

nts::Component4512::Component4512()
{
    std::vector<nts::node> list(16);
    pins = list;
}

nts::Component4512::~Component4512()
{
}

nts::Tristate nts::Component4512::compute(std::size_t pin)
{
    (void)pin;
    int a = pins[10].component->compute(pins[10].other_pin);
    int b = pins[11].component->compute(pins[11].other_pin);
    int c = pins[12].component->compute(pins[12].other_pin);
    int inhibit = pins[9].component->compute(pins[9].other_pin);
    int oe = pins[14].component->compute(pins[14].other_pin);
    std::cout << "inhibit: " << inhibit << std::endl;
    std::cout << "oe: " << oe << std::endl;
    if (c == False && b == False && a == False && inhibit == False && oe == False) {
        return pins[0].component->compute(pins[0].other_pin);
    } else if (c == False && b == False && a == True && inhibit == False && oe == False) {
        return pins[1].component->compute(pins[1].other_pin);
    } else if (c == False && b == True && a == False && inhibit == False && oe == False) {
        return pins[2].component->compute(pins[2].other_pin);
    } else if (c == False && b == True && a == True && inhibit == False && oe == False) {
        return pins[3].component->compute(pins[3].other_pin);
    } else if (c == True && b == False && a == False && inhibit == False && oe == False) {
        return pins[4].component->compute(pins[4].other_pin);
    } else if (c == True && b == False && a == True && inhibit == False && oe == False) {
        return pins[5].component->compute(pins[5].other_pin);
    } else if (c == True && b == True && a == False && inhibit == False && oe == False) {
        return pins[6].component->compute(pins[6].other_pin);
    } else if (c == True && b == True && a == True && inhibit == False && oe == False) {
        return pins[7].component->compute(pins[7].other_pin);
    } else if (inhibit == True && oe == False) {
        return False;
    } else if (oe == True) {
        return Undefined;
    } else {
        return Undefined;
    }
}
