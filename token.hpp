#ifndef tokenH
#define tokenH

#include <iostream>
#include <string>
#include <map>

namespace token {

    enum tokenId { idTok, keyTok, opTok, intTok, EOFTok};

    class Token {

        public:
            tokenId tokenId;
            std::string tokenInstance;
            int lineNumber, charNumber;

            Token();

            Token(token::tokenId id, std::string instance, int lineNum, int charNum) {
                tokenId = id;
                tokenInstance = instance;
                lineNumber = lineNum;
                charNumber = charNum;
            }
            
            void output() {
                std::cout << "{ " << tokenId << ", " << tokenInstance << ", " << lineNumber << "." << charNumber << " }";
            }
    };

}

#endif //tokenH