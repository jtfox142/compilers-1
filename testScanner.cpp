#include "scanner.hpp"
#include "token.hpp"

#include <stack>
#include <fstream>
#include <deque>

namespace {

    static std::deque<token::Token> _tokenList;
    static token::Token _lastToken;

}

void start(std::ifstream inputStream) {
    _lastToken.tokenId = token::tokenId::idTok;

    if(inputStream.is_open()) {
        while(_lastToken.tokenId != token::tokenId::EOFTok) {
            if(inputStream.fail() || inputStream.bad()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            _tokenList.push_back(scanner::getNextToken(inputStream));
            _lastToken = _tokenList.back();
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file. Possible bad file name.");
    }

    inputStream.close();
}

void print() {
    std::deque<token::Token>::iterator it;

    for(it = _tokenList.begin(); it != _tokenList.end(); it++) {
        (*it).output();
    }
}