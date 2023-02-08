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
    while (std::getline(std::cin, line)) {
        if (line == "exit")
            break;
        if (line == "display")
            display(myCircuit);
        if (line.find('=') != std::string::npos) {
            assignCommand(extractName(line), extractValue(line), myCircuit);
        } else
            std::cout << line << std::endl;
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
    nts::IComponent *comp = myCircuit.getComp(name);
    nts::InputComponent *component = dynamic_cast<nts::InputComponent *>(comp);
    if (component) {
        int valueNb = std::stoi(value);
        if (valueNb == nts::True)
            component->setValue(nts::True);
        if (valueNb == nts::False)
            component->setValue(nts::False);
        if (valueNb == nts::Undefined)
            component->setValue(nts::Undefined);
    }

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
                std::cout << it->first << ": " << "U" << std::endl;
            else
                std::cout << it->first << ": " << component->getValue() << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = myCircuit.getMap()->begin(); it != myCircuit.getMap()->end(); it++){
        nts::OutputComponent *component = dynamic_cast<nts::OutputComponent *>(it->second.get());
        if (component) {
            nts::Tristate val = component->compute(1);
            if (val == nts::Undefined)
                std::cout << it->first << ": " << "U" << std::endl;
            else
                std::cout << it->first << ": " << val << std::endl;
        }
    }
}