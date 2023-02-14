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

nts::IComponent *create4001()
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4001.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *create4011()
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4011.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *create4031()
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4030.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *create4071()
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4071.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *create4081()
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4081.nts");
    myParser.addChipsetsToCircuit(*circuit);
    // circuit->getComp("and1")->setLink(1, *circuit, 1);
    // circuit->getComp("and1")->setLink(2, *circuit, 2);
    // circuit->setLink(3, *circuit->getComp("and1"), 3);
    return circuit;
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    std::ifstream myfile (av[1]);
    if (myfile.is_open() == false)
        return 84;
    myfile.close();
    Parser myParser(av[1]);
    // myParser.showFile();
    Circuit circuit;
    Minishell minishell;
    myParser.addChipsetsToCircuit(circuit);
    myParser.addLinksToCircuit(circuit);
    minishell.getCommands(circuit);

    return 0;
}
