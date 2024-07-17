#include <noditto/hello.h>
#include <noditto/lexer/lexer.h>

int main() {
  Lexer lexer("int a = 10;");
  lexer.tokenize();

  return 0;
}