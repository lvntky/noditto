#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>

#include <noditto/lexer/token_type.hpp>

typedef struct token
{
  enum TokenType type;
  std::string value;
  int line;
  int column;
} token_t;

#endif  // TOKEN_H_
