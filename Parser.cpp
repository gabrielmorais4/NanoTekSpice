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
}

Parser::~Parser()
{
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