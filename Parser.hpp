/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <functional>
#include <memory>
#include <map>
#include "IComponent.hpp"
#include "AndComponent.hpp"
#include "NotComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"
#include "InputComponent.hpp"
#include "Circuit.hpp"
class Parser {
    public:
        Parser(const std::string &file);
        ~Parser();
        void showFile() const;
        void addChipsetsToCircuit(Circuit &circuit);
        void addLinksToCircuit(Circuit &circuit);
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> functs;
        nts::IComponent *create4069() const;
        nts::IComponent *create4071() const;
        nts::IComponent *create4081() const;
        nts::IComponent *create4001() const;
        nts::IComponent *create4011() const;
        nts::IComponent *create4030() const;


    protected:
    private:
        std::vector<std::string> chipsets;
        std::vector<std::string> links;
};
int checkIfValueExists(auto vector, std::string val);

#endif /* !PARSER_HPP_ */
