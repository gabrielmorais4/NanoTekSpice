/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        nts::node newnode = nts::node{&other,otherPin};
        pins.at(pin - 1) = newnode;
        if (other.getPinConnexion(otherPin) != nullptr)
            other.setLink(otherPin, *this, pin);
}


nts::IComponent *nts::AComponent::getPinConnexion(std::size_t index) {
    if (index >= pins.size()) {
        return nullptr;
    }
    return pins.at(index).component;
}