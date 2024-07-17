#include <noditto/commons/log_commons.hpp>
#include <noditto/lexer/lexer.hpp>
#include <noditto/tostring/tostring.hpp>

int main() {
  Lexer lexer("int a = 10;");
  std::vector<token_t> tokens = lexer.tokenize();

  for (size_t i = 0; i < tokens.size(); i++) {
    token_t currentToken = tokens.at(i);
    std::string currentTokenType = tokenTypeToString(currentToken.type);
    spdlog::info("{} - value: {}\ttype: {}\tcolumn: {}\t line: {}", i, currentToken.value,
                 currentTokenType, currentToken.column, currentToken.line);
  }

  return 0;
}