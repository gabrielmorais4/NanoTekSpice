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
#include "Minishell.hpp"
#include "OrComponent.hpp"
#include <memory>

int main ( void )
{
    Circuit circuit;
    Minishell minishell;
    circuit.addComp("output", new nts::OutputComponent());
    circuit.addComp("clock", new nts::ClockComponent());
    circuit.addComp("or", new nts::OrComponent());
    circuit.addComp("input", new nts::InputComponent());
    circuit.getComp("clock")->setLink(1, *circuit.getComp("or"), 1);
    circuit.getComp("input")->setLink(1, *circuit.getComp("or"), 2);
    circuit.getComp("or")->setLink(3, *circuit.getComp("output"), 1);
    minishell.getCommands(circuit);
}