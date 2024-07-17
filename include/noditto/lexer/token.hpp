#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <noditto/lexer/token_type.hpp>
#include <string>

typedef struct token {
  enum TokenType type;
  std::string value;
  int line;
  int column;
} token_t;

#endif  // TOKEN_H_
