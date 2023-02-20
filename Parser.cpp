/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string &file)
{
    try {
    std::ifstream myfile (file);
    std::string line;
    bool isChipsets = true;
    while (std::getline(myfile, line)) {
        int pos = line.find('#');
        line = line.substr(0, pos);
        std::istringstream iss(line);
        std::string val;
        std::string fullstring;
        iss >> fullstring;
        while(iss >> val) {
            if (val[0] == '#')
                continue;
            fullstring += " ";
            fullstring += val;
        }
        if (fullstring[0] != '#' && !fullstring.empty()) {
            if (fullstring == ".links:") {
                isChipsets = false;
                continue;
            }
            if (fullstring == ".chipsets:") {
                isChipsets = true;
                continue;
            }
            if (isChipsets) {
                if (checkIfValueExists(chipsets, fullstring)) {
                    exit (12);
                }
                chipsets.insert(chipsets.end(), fullstring);
            }
            else
                links.insert(links.end(), fullstring);
        }
    }
    } catch (std::exception &e) {
        exit (13);
    }
    functs.insert({"and", [](){ return std::make_unique<nts::AndComponent>(); }});
    functs.insert({"not", [](){ return std::make_unique<nts::NotComponent>(); }});
    functs.insert({"output", [](){ return std::make_unique<nts::OutputComponent>(); }});
    functs.insert({"clock", [](){ return std::make_unique<nts::ClockComponent>(); }});
    functs.insert({"or", [](){ return std::make_unique<nts::OrComponent>(); }});
    functs.insert({"xor", [](){ return std::make_unique<nts::XorComponent>(); }});
    functs.insert({"input", [](){ return std::make_unique<nts::InputComponent>(); }});
    functs.insert({"false", [](){ return std::make_unique<nts::FalseComponent>(); }});
    functs.insert({"true", [](){ return std::make_unique<nts::TrueComponent>(); }});
    functs.insert({"4069", [](){ return create4069(); }});
    functs.insert({"4001", [](){ return create4001(); }});
    functs.insert({"4011", [](){ return create4011(); }});
    functs.insert({"4030", [](){ return create4030(); }});
    functs.insert({"4071", [](){ return create4071(); }});
    functs.insert({"4081", [](){ return create4081(); }});

    if (chipsets.empty() || links.empty())
        exit(11);
}

int checkIfValueExists(auto vector, std::string val)
{
    for (auto it : vector) {
        if (it == val)
            return 1;
    }
    return 0;
}

Parser::~Parser()
{
}

void Parser::addChipsetsToCircuit(Circuit &circuit)
{
    for (auto it : chipsets) {
        std::stringstream ss(it);
        std::string type, name;
        ss >> type >> name;
        try {
            circuit.addComp(name, functs[type]());
        } catch (std::exception &e) {
                exit (16);
        }
    }
}

void Parser::addLinksToCircuit(Circuit &circuit)
{
    for (auto it : links) {
        std::stringstream ss(it);
        std::string first, second;
        ss >> first >> second;
        std::string firstName, firstPin, secondName, secondPin;
        size_t pos;
        pos = first.find(':');
        firstName = first.substr(0, pos);
        firstPin = first.substr(pos + 1);
        pos = second.find(':');
        secondName = second.substr(0, pos);
        secondPin = second.substr(pos + 1);
        try {
        circuit.getComp(firstName)->setLink(std::stoi(firstPin), *circuit.getComp(secondName), std::stoi(secondPin));
        } catch (std::exception &e) {
            exit (17);
        }
    }
}

void Parser::showFile () const
{
    std::cout << "here's list of chipsets" << std::endl;
    for (auto it : chipsets) {
        std::cout << it << std::endl;
    }
    std::cout << "here's list of links" << std::endl;
    for (auto it : links) {
        std::cout << it << std::endl;
    }
}

void Parser::addLinksToCircuitCustom(Circuit &circuit)
{
    for (auto it : links) {
        std::stringstream ss(it);
        std::string first, second;
        ss >> first >> second;
        std::string firstName, firstPin, secondName, secondPin;
        size_t pos;
        pos = first.find(':');
        firstName = first.substr(0, pos);
        firstPin = first.substr(pos + 1);
        pos = second.find(':');
        secondName = second.substr(0, pos);
        secondPin = second.substr(pos + 1);
        try {
            if (firstName == "circuit" && secondName != "circuit") {
                circuit.setUnidirectionalLink(std::stoi(firstPin), *circuit.getComp(secondName), std::stoi(secondPin));
            }
            if (firstName != "circuit" && secondName == "circuit") {
                circuit.getComp(firstName)->setUnidirectionalLink(std::stoi(firstPin), circuit, std::stoi(secondPin));
            }
            if (firstName == "circuit" && secondName == "circuit") {
                circuit.setUnidirectionalLink(std::stoi(firstPin), circuit, std::stoi(secondPin));
            }
            if (firstName != "circuit" && secondName != "circuit") {
                circuit.getComp(firstName)->setUnidirectionalLink(std::stoi(firstPin), *circuit.getComp(secondName), std::stoi(secondPin));
            }
        } catch (std::exception &e) {
            exit (18);
        }
    }
}

std::unique_ptr<nts::IComponent> create4069()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4069.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}

std::unique_ptr<nts::IComponent> create4001()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4001.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}

std::unique_ptr<nts::IComponent> create4011()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4011.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}

std::unique_ptr<nts::IComponent> create4030()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4030.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}

std::unique_ptr<nts::IComponent> create4071()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4071.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}

std::unique_ptr<nts::IComponent> create4081()
{
    std::unique_ptr<Circuit> circuit(new Circuit(14));
    Parser myParser("./nts_files/4081.nts");
    myParser.addChipsetsToCircuit(*circuit);
    myParser.addLinksToCircuitCustom(*circuit);
    return std::unique_ptr<nts::IComponent>(std::move(circuit));
}
