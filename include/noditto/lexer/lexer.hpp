#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <noditto/lexer/token.hpp>
#include <string>
#include <vector>

class Lexer {
public:
  Lexer(const std::string&);
  std::vector<token_t> tokenize();

private:
  char getCurrentChar();
  void advance();
  void skipWhiteSpace();
  token_t createToken(TokenType type, const std::string& value);

  std::string source;
  size_t position;
  int line;
  int column;
};

#endif  // LEXER_H_
