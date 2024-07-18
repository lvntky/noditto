#include <fstream>
#include <iostream>
#include <noditto/commons/log_commons.hpp>
#include <noditto/lexer/lexer.hpp>
#include <noditto/tostring/tostring.hpp>

std::string readFileToString(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return "";
  }

  std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

  file.close();
  return content;
}

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
    spdlog::info("{} - value: {}\ttype: {}\tcolumn: {}\t line: {}", i, currentToken.value,
                 currentTokenType, currentToken.column, currentToken.line);
  }

  return 0;
}
