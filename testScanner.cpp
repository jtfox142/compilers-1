#include "testScanner.hpp"
#include "scanner.hpp"
#include "token.hpp"

#include <iostream>
#include <stack>
#include <fstream>
#include <deque>

namespace {

    static std::deque<token::Token> _tokenList;
    static token::Token _lastToken;

}

//TODO filter for comments
void testScanner::start(std::string fileName) {
    _lastToken.tokenId = token::tokenId::idTok;
    std::ifstream inputStream (fileName.c_str());

    if(inputStream.is_open()) {
        std::cout << "ifstream open. testScanner starting.\n";
        while(_lastToken.tokenId != token::tokenId::EOFTok) {
            if(inputStream.fail() || inputStream.bad()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            std::string tokenString;
            //Only works with tokens delimited by whitespace
            inputStream >> tokenString;

            std::cout << "About to pushback\n";
            _tokenList.push_back(scanner::getNextToken(tokenString));
            _lastToken = _tokenList.back();
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file. Possible bad file name.");
    }

    inputStream.close();
    std::cout << "testScanner start complete.\n";
}

void testScanner::print() {
    std::deque<token::Token>::iterator it;

    std::cout << "testScanner outputting.\n";
    for(it = _tokenList.begin(); it != _tokenList.end(); it++) {
        (*it).output();
    }
}