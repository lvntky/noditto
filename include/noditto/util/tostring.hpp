#ifndef TO_STRING_HPP_
#define TO_STRING_HPP_
#include <noditto/lexer/token_type.hpp>
#include <string>

std::string tokenTypeToString(TokenType type) {
  switch (type) {
    case TokenType::Keyword:
      return "Keyword";
    case TokenType::Identifier:
      return "Identifier";
    case TokenType::Number:
      return "Number";
    case TokenType::Operator:
      return "Operator";
    case TokenType::EndOfFile:
      return "EndOfFile";
    default:
      return "Unknown";
  }
}

#endif