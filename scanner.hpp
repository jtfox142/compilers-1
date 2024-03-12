#ifndef scannerH
#define scannerH

#include "token.hpp"

#include <string>
#include <vector>
#include <deque>

namespace scanner {

    token::Token getNextToken(std::string);

}  // namespace scanner

#endif  // scannerH