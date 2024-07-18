#include <fstream>
#include <iostream>
#include <noditto/commons/log_commons.hpp>
#include <noditto/lexer/lexer.hpp>
#include <noditto/util/tostring.hpp>
#include <noditto/util/file_util.hpp>

int main(int argc, char** argv) {
  if (argc < 1) {
    spdlog::error("error");
    throw std::runtime_error("Provide file to check: ./Noditto <file.cpp>");
  }

  std::string fileToheck = readFileToString(argv[1]);

  Lexer lexer(fileToheck);
  std::vector<token_t> tokens = lexer.tokenize();

  for (size_t i = 0; i < tokens.size(); i++) {
    token_t currentToken = tokens.at(i);
    std::string currentTokenType = tokenTypeToString(currentToken.type);
    spdlog::info("{} - value: {}\t type: {}\t column: {}\t line: {}", i, currentToken.value,
                 currentTokenType, currentToken.column, currentToken.line);
  }

  return 0;
}
