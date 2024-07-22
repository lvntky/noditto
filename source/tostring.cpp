#include <noditto/util/tostring.hpp>

std::string tokenTypeToString(TokenType type)
{
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