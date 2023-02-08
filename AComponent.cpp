/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        pins[pin - 1].component = &other;
        pins[pin - 1].other_pin = otherPin;
        if (other.getPinConnexion(otherPin) == nullptr) {
            other.setLink(otherPin, *this, pin);
        }
}


nts::IComponent *nts::AComponent::getPinConnexion(std::size_t index)
{
    if (index - 1 >= pins.size()) {
        std::cout << "Pin doesn't exist" << std::endl;
        return nullptr;
    }
    return pins.at(index - 1).component;
}
