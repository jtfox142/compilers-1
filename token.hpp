#ifndef tokenH
#define tokenH

#include <iostream>
#include <string>
#include <map>

namespace token {

    enum tokenId { idTok, keyTok, opTok, intTok, EOFTok};

    class Token {

        public:
            inline Token() {
                tokenId = tokenId::idTok;
                tokenInstance = "";
                lineNumber = -1;
                charNumber = -1;
            };

            inline Token(tokenId id, std::string instance, int lineNum, int charNum) {
                tokenId = id;
                tokenInstance = instance;
                lineNumber = lineNum;
                charNumber = charNum;
            }
            tokenId tokenId;
            std::string tokenInstance;
            int lineNumber, charNumber;
            
            void output() {
                std::cout << "{ " << tokenId << ", " << tokenInstance << ", " << lineNumber << "." << charNumber << " }" << std::endl;
            }
    };

}

#endif //tokenH