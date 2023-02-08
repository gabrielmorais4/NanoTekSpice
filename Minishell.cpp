/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Minishell
*/

#include "Minishell.hpp"

Minishell::Minishell()
{
}

Minishell::~Minishell()
{
}

void Minishell::getCommands(Circuit &myCircuit)
{
    std::string line;
    while (!std::cin.eof()) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;
        if (line == "display")
            display(myCircuit);
        if (line == "simulate")
            simulate(myCircuit);
        if (line.find('=') != std::string::npos)
            assignCommand(extractName(line), extractValue(line), myCircuit);
    }
}

void Minishell::assignCommand(const std::string &name, const std::string &value, Circuit &myCircuit)
{
    if (value.empty() || !std::all_of(value.begin(), value.end(), ::isdigit)) {
        std::cout << "WRONG VALUE" << std::endl;
        return;
    }
    if (name.empty()) {
        std::cout << "WRONG VALUE" << std::endl;
        return;
    }
    if (myCircuit.getComp(name) == nullptr) {
        std::cout << "WRONG VALUE" << std::endl;
        return;
    }
    mapAssign.insert({name, (nts::Tristate)std::stoi(value)});
}

std::string extractName(std::string const &value)
{
    std::string::size_type pos = value.find('=');
    if (pos != std::string::npos) {
        return value.substr(0,pos);
    } else {
        return value;
    }
}

std::string extractValue(const std::string &value)
{
    return value.substr(value.find('=') + 1);
}

void Minishell::display(Circuit &myCircuit)
{
    std::cout << "tick: " << myCircuit.getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = myCircuit.getMap()->begin(); it != myCircuit.getMap()->end(); it++){
        nts::InputComponent *component = dynamic_cast<nts::InputComponent *>(it->second.get());
        if (component) {
            if (component->getValue() == nts::Undefined)
                std::cout << "\t" << it->first << ": " << "U" << std::endl;
            else
                std::cout << "\t" << it->first << ": " << component->getValue() << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = myCircuit.getMap()->begin(); it != myCircuit.getMap()->end(); it++){
        nts::OutputComponent *component = dynamic_cast<nts::OutputComponent *>(it->second.get());
        if (component) {
            nts::Tristate val = component->compute(1);
            if (val == nts::Undefined)
                std::cout << "\t" << it->first << ": " << "U" << std::endl;
            else
                std::cout << "\t" << it->first << ": " << val << std::endl;
        }
    }
}

void Minishell::simulate(Circuit &myCircuit)
{
    for (auto &it : mapAssign){
        nts::InputComponent *component = dynamic_cast<nts::InputComponent *>(myCircuit.getComp(it.first));
        if (component) {
           component->setValue(it.second);
        }
    }
    for(auto &it : *myCircuit.getMap()) {
        nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(myCircuit.getComp(it.first));
        if (clock) {
            clock->simulate(myCircuit.getTick());
        }
    }
    mapAssign.clear();
    myCircuit.setTick(myCircuit.getTick() + 1);
}
