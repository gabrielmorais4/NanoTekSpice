/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-tekspice-gabriel.de-souza-morais
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string &file)
{
    std::ifstream myfile (file);
    std::string line;
    bool isChipsets = true;
    while (std::getline(myfile, line)) {
        if (line == ".links:") {
            isChipsets = false;
            continue;
        }
        if (line == ".chipsets:") {
            isChipsets = true;
            continue;
        }
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
            if (isChipsets)
                chipsets.insert(chipsets.end(), fullstring);
            else
                links.insert(links.end(), fullstring);
        }
    }
    functs.insert({"and", [](){ return std::make_unique<nts::AndComponent>(); }});
    functs.insert({"not", [](){ return std::make_unique<nts::NotComponent>(); }});
    functs.insert({"output", [](){ return std::make_unique<nts::OutputComponent>(); }});
    functs.insert({"clock", [](){ return std::make_unique<nts::ClockComponent>(); }});
    functs.insert({"or", [](){ return std::make_unique<nts::OrComponent>(); }});
    functs.insert({"xor", [](){ return std::make_unique<nts::OrComponent>(); }});
    functs.insert({"input", [](){ return std::make_unique<nts::InputComponent>(); }});
    functs.insert({"false", [](){ return std::make_unique<nts::FalseComponent>(); }});
    functs.insert({"true", [](){ return std::make_unique<nts::TrueComponent>(); }});

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
        std::cout << type << std::endl;
       circuit.addComp(name, functs[type]());
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
        circuit.getComp(firstName)->setLink(std::stoi(firstPin), *circuit.getComp(secondName), std::stoi(secondPin));
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

nts::IComponent *Parser::create4069() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4069.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *Parser::create4001() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4001.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *Parser::create4011() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4011.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *Parser::create4030() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4030.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *Parser::create4071() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4071.nts");
    myParser.addChipsetsToCircuit(*circuit);
    //link
    return circuit;
}

nts::IComponent *Parser::create4081() const
{
    Circuit *circuit = new Circuit(14);
    Parser myParser("./nts_files/4081.nts");
    myParser.addChipsetsToCircuit(*circuit);
    // circuit->getComp("and1")->setLink(1, *circuit, 1);
    // circuit->getComp("and1")->setLink(2, *circuit, 2);
    // circuit->setLink(3, *circuit->getComp("and1"), 3);
    return circuit;
}
