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

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    std::ifstream myfile (av[1]);
    if (myfile.is_open() == false)
        return 84;
    myfile.close();
    Parser myParser(av[1]);
    myParser.showFile();
    Circuit circuit;
    Minishell minishell;
    // myParser.addChipsetsToCircuit(circuit);
    myParser.addChipsetsToCircuit(circuit);
    myParser.addLinksToCircuit(circuit);
    minishell.getCommands(circuit);

    return 0;
}
