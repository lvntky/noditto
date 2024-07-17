#include <iostream>
#include <noditto/commons/log_commons.hpp>
#include <noditto/lexer/lexer.hpp>

Lexer::Lexer(const std::string& source) {
  this->source = source;
  this->column = 1;
  this->line = 1;
  this->position = 0;
}

char Lexer::getCurrentChar() {
  return this->position < this->source.length() ? source.at(position) : '\0';
}

void Lexer::advance() {
  this->position++;
  this->column++;

  if (getCurrentChar() == '\n') {
    this->line++;
    this->column = 1;
  }
}

void Lexer::skipWhiteSpace() {
  if (isspace(getCurrentChar())) {
    this->advance();
  }
}

token_t Lexer::createToken(TokenType type, const std::string& value) {
  return token_t{type, value, line, column};
}

std::vector<token_t> Lexer::tokenize() {
  std::vector<token_t> tokens;
  while (position < source.length()) {
    char ch = getCurrentChar();
    if (isspace(ch)) {
      skipWhiteSpace();
    } else if (isalpha(ch) || ch == '_') {
      std::string identifier;
      while (isalnum(getCurrentChar()) || getCurrentChar() == '_') {
        identifier += getCurrentChar();
        advance();
      }
      tokens.push_back(createToken(TokenType::Identifier, identifier));
    } else if (isdigit(ch)) {
      std::string number;
      while (isdigit(getCurrentChar())) {
        number += getCurrentChar();
        advance();
      }
      tokens.push_back(createToken(TokenType::Number, number));
    } else if (ispunct(ch)) {
      tokens.push_back(createToken(TokenType::Operator, std::string(1, ch)));
      advance();
    } else {
      tokens.push_back(createToken(TokenType::Unknown, std::string(1, ch)));
      advance();
      std::cout << getCurrentChar() << std::endl;
    }
  }
  tokens.push_back(createToken(TokenType::EndOfFile, ""));
  return tokens;
}