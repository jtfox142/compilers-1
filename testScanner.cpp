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
    _lastToken.tokenId = token::tokenIdList::idTok;
    std::ifstream inputStream (fileName.c_str());

    if(inputStream.is_open()) {
        while(_lastToken.tokenId != token::tokenIdList::EOFTok) {
            if(inputStream.fail() || inputStream.bad()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            //std::string line;
            //std:getline(inputStream, line);
            std::string tokenString;
            //Only works with tokens delimited by whitespace
            inputStream >> tokenString;

            _tokenList.push_back(scanner::getNextToken(tokenString));
            _lastToken = _tokenList.back();
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file. Possible bad file name.");
    }

    inputStream.close();
} 

void testScanner::print() {
    std::deque<token::Token>::iterator it;
    std::string tokenIdArray[] = {"idTok", "keyTok", "opTok", "intTok", "EOFTok"};

    for(it = _tokenList.begin(); it != _tokenList.end(); it++) {
        if((*it).tokenInstance == "" && (*it).tokenId == -1)
            continue; 
        std::cout << "{ " << tokenIdArray[(*it).tokenId] << ", " << (*it).tokenInstance << ", " << (*it).lineNumber << "." << (*it).charNumber << " }" << std::endl;
    }
}