/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Minishell
*/

#pragma once

#include <iostream>
#include <string>
#include "Circuit.hpp"
class Minishell {
    public:
        Minishell();
        ~Minishell();
        void getCommands(Circuit &myCircuit);
        void assignCommand(const std::string &name, const std::string &value, Circuit &myCircuit);
        void display(Circuit &myCircuit);
    protected:
    private:
};
std::string extractName(std::string const &value);
std::string extractValue(const std::string &value);

