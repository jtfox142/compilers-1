#ifndef scannerH
#define scannerH

#include "token.hpp"

#include <string>
#include <vector>
#include <deque>

namespace scanner {

    token::Token getNextToken(std::ifstream& inputStream);

};  // namespace scanner

#endif  // scannerH