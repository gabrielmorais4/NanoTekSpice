/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** IComponent
*/

#pragma once

#include <iostream>

namespace nts
{
    enum Tristate {
        Undefined = (-true) ,
        True = true ,
        False = false
    };

    class IComponent {
        public :
            virtual ~IComponent() = default ;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setUnidirectionalLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::IComponent *getPinConnexion(std::size_t index) = 0;
            virtual void setVisited(bool visited) = 0;
    };
}
