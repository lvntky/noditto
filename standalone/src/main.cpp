#include <noditto/lexer/lexer.hpp>

int main() {
  Lexer lexer("int a = 10;");
  lexer.tokenize();

  return 0;
}