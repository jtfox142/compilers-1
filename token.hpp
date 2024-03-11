#ifndef tokenH
#define tokenH

#include <iostream>
#include <string>

enum tokenId { idTok, keyTok, varNameTok, opTok, intTok, EOFTok};

class Token {
    tokenId tokenId;
    std::string tokenInstance;
    int lineNumber, charNumber;

    void output() {
        std::cout << "{ " << tokenId << ", " << tokenInstance << ", " << lineNumber << "." << charNumber << " }";
    }
};

#endif //tokenH