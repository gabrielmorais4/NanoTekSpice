/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** main
*/

#include <iostream>
#include "Circuit.hpp"
#include "AndComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "NotComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"
#include <memory>

int main ( void )
{
    Circuit circuit;
    // circuit.addComp("output", new nts::OutputComponent());
    // circuit.addComp("true", new nts::TrueComponent());
    // circuit.addComp("true2", new nts::TrueComponent());
    // circuit.addComp("and", new nts::AndComponent());
    // circuit.addComp("not", new nts::NotComponent());
    // circuit.getComp("true")->setLink(1, *circuit.getComp("and"), 1);
    // circuit.getComp("true2")->setLink(1, *circuit.getComp("and"), 2);
    // circuit.getComp("and")->setLink(3, *circuit.getComp("not"), 1);
    circuit.addComp("clock", new nts::ClockComponent());
    circuit.addComp("output", new nts::OutputComponent());
    circuit.getComp("clock")->setLink(1, *circuit.getComp("output"), 1);
    circuit.display();
    // circuit.getComp("clock")->compute(1);
    // circuit.getComp("clock")->compute(1);
    // circuit.getComp("clock")->compute(1);
    circuit.display();
}
