#include "scanner.hpp"
#include "token.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

/*
TODO
* Implement line and char numbers
* 

*/

namespace {

    static std::deque<std::string> _userInput;
    static std::string _fileName;
    static const std::vector<std::string> _keywords { 
        "start", "stop", "while", 
        "repeat", "until", "label", 
        "return", "cin", "cout", 
        "tape", "jump", "if", 
        "then", "pick", "create", 
        "set", "func" 
    };
    static int _lineNumber = 0;

} //namespace

bool isKeyword(std::string tokenString) {
    bool found = (std::find(_keywords.begin(), _keywords.end(), tokenString) != _keywords.end());
    return found;
}

bool isValidIdTok(std::string tokenString) {
    //Test if the idTok contains special characters
    for(std::string::iterator it = tokenString.begin(); it != tokenString.end(); ++it) {
        if(!isalnum(*it) && (*it) != '_') {
            return false;
        }
    }

    return true;
}

bool isValidIntTok(std::string tokenString) {
    //Test if the intTok contains non-numbers
    for(std::string::iterator it = tokenString.begin(); it != tokenString.end(); ++it) {
        if(!isdigit(*it)) {
            return false;
        }
    }

    return true;
}

//Grabs the next token. Tests the first char, identifies the most likely token type,
//then checks for errors or reserved words
token::Token scanner::getNextToken(std::string tokenString) {
    //_lineNumber++;

    token::Token token;
    token.tokenInstance = tokenString;
    //token.lineNumber = _lineNumber;

    if(tokenString == "") {
        token::Token eof(token::tokenId::EOFTok, "EOF", 0, 0);
        return eof;
    }

    char beginningChar = tokenString.at(0);
        
    //If the beginning char is a letter, then it is an identifier token
    if(isalpha(beginningChar)) {
        //Check for reserved words
        if(isKeyword(tokenString))
            token.tokenId = token::tokenId::keyTok;
        else {
            //Checks the word for illegal characters
            if(isValidIdTok(tokenString)) 
                token.tokenId = token::tokenId::idTok;
            else {
                std::cerr << "ERROR: idTok " << tokenString << " contains an illegal character.";
                exit(1);
            }
        }
    }
    else if(isdigit(beginningChar)) {
        if(isValidIntTok(tokenString)) {
            token.tokenId = token::tokenId::intTok;
        }
        else {
            std::cerr << "ERROR: intTok " << tokenString << " contains an illegal character.";
            exit(1);
        }
    }
    else {
        token.tokenId = token::tokenId::opTok;
    }

    return token;
}