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

class Parser {
    public:
        Parser(const std::string &file);
        ~Parser();
        void showFile() const;
    protected:
    private:
        std::vector<std::string> chipsets;
        std::vector<std::string> links;
};

#endif /* !PARSER_HPP_ */
