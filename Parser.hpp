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
#include "SumComponent.hpp"
#include "LoggerComponent.hpp"
class Parser {
    public:
        Parser(const std::string &file);
        ~Parser();
        void showFile() const;
        void addChipsetsToCircuit(Circuit &circuit);
        void addLinksToCircuit(Circuit &circuit);
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> functs;
        void addLinksToCircuitCustom(Circuit &circuit);

    protected:
    private:
        std::vector<std::string> chipsets;
        std::vector<std::string> links;
};
int checkIfValueExists(auto vector, std::string val);
std::unique_ptr<nts::IComponent> create4069();
std::unique_ptr<nts::IComponent> create4001();
std::unique_ptr<nts::IComponent> create4011();
std::unique_ptr<nts::IComponent> create4030();
std::unique_ptr<nts::IComponent> create4071();
std::unique_ptr<nts::IComponent> create4081();
std::unique_ptr<nts::IComponent> create4008();

#endif /* !PARSER_HPP_ */
