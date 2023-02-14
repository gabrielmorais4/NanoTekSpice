/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** main
*/

#include <iostream>
#include "Circuit.hpp"

#include "Minishell.hpp"
#include <memory>
#include <fstream>
#include <string>
#include "Parser.hpp"

nts::IComponent *create4081()
{
    Circuit *circuit = new Circuit(12);
    Parser myParser("./nts_files/4081.nts");
    myParser.addChipsetsToCircuit(*circuit);
    // circuit->getComp("and1")->setLink(1, *circuit, 1);
    // circuit->getComp("and1")->setLink(2, *circuit, 2);
    // circuit->setLink(3, *circuit->getComp("and1"), 3);
    // circuit->getComp("and2")->setLink(1, *circuit, 4);
    // circuit->getComp("and2")->setLink(2, *circuit, 5);
    // circuit->getComp("and2")->setLink(3, *circuit, 6);
    // circuit->getComp("and3")->setLink(1, *circuit, 7);
    // circuit->getComp("and3")->setLink(2, *circuit, 8);
    // circuit->getComp("and3")->setLink(3, *circuit, 9);
    // circuit->getComp("and4")->setLink(1, *circuit, 10);
    // circuit->getComp("and4")->setLink(2, *circuit, 11);
    // circuit->getComp("and4")->setLink(3, *circuit, 12);
    return circuit;
}

int main (int ac, char **av)
{
    // if (ac != 2)
    //     return 84;
    // std::ifstream myfile (av[1]);
    // if (myfile.is_open() == false)
    //     return 84;
    // myfile.close();
    // Parser myParser(av[1]);
    // myParser.showFile();
    Circuit circuit;
    Minishell minishell;
    // myParser.addChipsetsToCircuit(circuit);
    // myParser.addLinksToCircuit(circuit);
    circuit.addComp("input", std::unique_ptr<nts::IComponent>(new nts::InputComponent()));
    circuit.addComp("input2", std::unique_ptr<nts::IComponent>(new nts::InputComponent()));
    circuit.addComp("output", std::unique_ptr<nts::IComponent>(new nts::OutputComponent()));
    circuit.addComp("4081", std::unique_ptr<nts::IComponent>(create4081()));
    circuit.getComp("4081")->setLink(1, *circuit.getComp("input"), 1);
    circuit.getComp("4081")->setLink(2, *circuit.getComp("input2"), 1);
    circuit.getComp("output")->setLink(1, *circuit.getComp("4081"), 3);
    minishell.getCommands(circuit);

    return 0;
}
